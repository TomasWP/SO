#!/bin/bash
#
#
#  author Paulo Macedo 
# 
#
# Function to generate random numbers

generate_random() {
    min=$1
    max=$2
    range=$((max - min + 1))
    echo $(($RANDOM % range + min))
}

# Function to generate random spaces
generate_spaces() {
    num_spaces=$(generate_random $1 $2)
    spaces=$(printf '%*s' "$num_spaces")
    echo "$spaces"
}

# Function to generate address space profile array
generate_address_space() {
    size=$(generate_random 1 4)
    address_space=""
    for ((i = 1; i <= size; i++)); do
        if [ "$i" -gt 1 ]; then
            address_space+=","
        fi
        address_space+="$(generate_random 256 2048)"
    done

    echo "$address_space"
}

generate_unique_pids() {
    local n=$1
    local min_pid=100
    local max_pid=1000
    local pid_list=()

    while [ ${#pid_list[*]} -lt "$n" ]; do
        local pid=$(generate_random "$min_pid" "$max_pid")

        # Check if the generated PID is already in the list
        if [[ ! " ${pid_list[*]} " =~ " $pid " ]]; then
            pid_list+=("$pid")
        fi
    done

    echo ${pid_list[*]} # the list of elements in the array
}

# Generate random content for the file
generate_content() {
    local arrival=0
    local process=$(generate_random 0 100)
    local pids=()
    
    pids=($(generate_unique_pids "$process"))

    for ((i = 0; i < process; i++)); do
        local random=$(generate_random 1 20)
        local lifetime=$(generate_random 10 1000)
        local address_space=$(generate_address_space)
        
        # Give ~1/7 probability of putting a % in the start of the line  
        if [ "$random" -le 3 ]; then
            echo -n "%"
        fi
        
        # Gives a 1/4 probability of putting spaces between fields (1/3 chance of having spaces)
        if [ "$random" -le 5 ]; then
            for ((k = 0; k < 8; k++)); do
                space_prob=$(generate_random 0 2)
                if [ "$space_prob" -eq 0 ]; then
                    spaces_array[$k]=$(generate_spaces 1 3)
                else 
                    spaces_array[$k]=""
                fi
            done
            line="${spaces_array[0]}${pids[$i]}${spaces_array[1]};${spaces_array[2]}$arrival${spaces_array[3]};${spaces_array[4]}$lifetime${spaces_array[5]};${spaces_array[6]}$address_space${spaces_array[7]}"
            echo "$line"
        else  
            line="${pids[$i]};$arrival;$lifetime;$address_space"
            echo "$line"
        fi

        # Gives a 1/10 probability of add newline and 1/20 to add a new line with % (can have some spaces before)
        if [ "$random" -le 2 ]; then
            echo "" 
            if [ "$random" -eq 1 ]; then
                spaces=$(generate_spaces 0 25)
                echo "$spaces%" 
            fi
        fi
        
        # ~= 1/3 probability of giving the same arrival time else generates new arrival time
        if [ "$random" -gt 7 ]; then
            arrival=$((arrival + $(generate_random 0 100)))
        fi
    done

    echo ""
}

# Sends random simulation content to randomsim.txt
random_sim_file(){
    generate_content > "./examples/randomsim.txt"

    if [ $? -eq 0 ]; then
        echo -e "\e[33m Simulation file created at /examples/randomsim.txt.\e[0m" 
    else
        echo -e "\e[31m Error while creating simulation file !\e[0m"
        exit 1
    fi
}

# Compiles the current code
compileCode(){
    cd ./build/

    if [ $? -eq 0 ]; then
        # 'make' command, which looks for a file named Makefile
        make
        if [ $? -eq 0 ]; then
            echo -e "\e[32m Code compiled !\e[0m" 
        else
            echo -e "\e[31m Couldn't compile!\e[0m"
            exit 1
        fi
    else
        echo -e "\e[33m Using previous compilation !\e[0m"
    fi

    cd ../
}

# Executes two binary versions and sends output to a file
run_versions(){
    timeout 4s ./bin/main -b -i ./examples/randomsim.txt $2 -o ./examples/correctOutput.txt

    if [ $? -eq 0 ]; then
        echo -e "\e[32m correctOutput.txt created. \e[0m"
    else
        echo -e "\e[31m Failed when creating the correctOutput.txt !\e[0m"
        exit 1
    fi

    timeout 4s ./bin/main -b -i ./examples/randomsim.txt $1 -o ./examples/myOutput.txt

    if [ $? -eq 0 ]; then
        echo -e "\e[32m myOutput.txt created. \e[0m" 
    else
        echo -e "\e[31m Failed when creating the myOutput.txt !\e[0m" 
        exit 1
    fi
}

# Using different methods to compare files says if files are equal
compare_output(){
    cmp -s ./examples/correctOutput.txt ./examples/myOutput.txt

    if [ $? -eq 0 ]; then
        echo -e "\e[92m\e[1m SUCCESSFULL TEST\e[22m\e[0m" 
    else
        echo -e "\e[91m\e[1m Sorry but... \e[22m\e[0m"
        meld ./examples/correctOutput.txt ./examples/myOutput.txt || diff ./examples/correctOutput.txt ./examples/myOutput.txt || cmp ./examples/correctOutput.txt ./examples/myOutput.txt
        exit 1
    fi
}

display_help() {

    echo -e "Your \e[4mmain.cpp\e[24m must include this simulation functions"
    echo -e "\e[4:3m\e[58:2::255:146:87m\e[3mif (infile != NULL)\e[23m\e[59m\e[4:0m"
    echo -e "\e[4:3m\e[58:2::255:146:87m\e[3m{\e[23m\e[59m\e[4:0m"
    echo -e "    \e[4:3m\e[58:2::255:146:87m\e[3msimLoad(infile);\e[23m\e[59m\e[4:0m"
    echo -e "    \e[4:3m\e[58:2::255:146:87m\e[3mwhile(simStep()){\e[23m\e[59m\e[4:0m"
    echo -e "        \e[4:3m\e[58:2::225:125:87m\e[3msimPrint(fout);\e[23m\e[59m\e[4:0m"
    echo -e "        \e[4:3m\e[58:2::225:125:87m\e[3mpctPrint(fout);\e[23m\e[59m\e[4:0m"
    echo -e "        \e[4:3m\e[58:2::225:125:87m\e[3mfeqPrint(fout);\e[23m\e[59m\e[4:0m"
    echo -e "        \e[4:3m\e[58:2::225:125:87m\e[3mswpPrint(fout);\e[23m\e[59m\e[4:0m"
    echo -e "        \e[4:3m\e[58:2::225:125:87m\e[3mmemPrint(fout);\e[23m\e[59m\e[4:0m"
    echo -e "    \e[4:3m\e[58:2::255:146:87m\e[3m}\e[23m\e[59m\e[4:0m"
    echo -e "\e[4:3m\e[58:2::255:146:87m\e[3m}\e[23m\e[59m\e[4:0m"
    echo -e ""

    echo "TEST OPTIONS:"

    echo "  -s simulations --- number of simulation tests (default: 3)"
    echo "  -c size        --- chunk size (default: 256 or 0x100)"
    echo "  -m size        --- total memory size, in bytes, (default: 1048576 or 0x100000)"
    echo "  -k address     --- memory size, in bytes, used by (kernel) OS (default: 65536 or 0x10000)"
    echo "  -r num-num     --- remove range of IDs from bin selection map"
    echo "  -b             --- set buddy system as the allocation policy (default: first fit)"
    echo "  -h             --- print this help"
}

main(){
    local n_simulations=3
    local args1=""
    local args2=""

    while getopts ":c:m:s:k:r:bh" opt; do
        case $opt in
            s)  n_simulations=$OPTARG ;;
            c)  args1="${args1}-c ${OPTARG} "
                args2="${args2}-c ${OPTARG} "
                ;;
            m)  args1="${args1}-m ${OPTARG} " 
                args2="${args2}-m ${OPTARG} " 
                ;;
            k)  args1="${args1}-k ${OPTARG} "
                args2="${args2}-k ${OPTARG} "
                ;;
            r)  args1="${args1}-r ${OPTARG} " 
                ;;
            b)  args1="${args1}-f b "
                args2="${args2}-f b "
                ;;
            h) display_help
               exit 0;;
            \?) echo "Invalid option: -$OPTARG" >&2
                exit 1 ;;
            :) echo "Option -$OPTARG requires an argument." >&2
               exit 1 ;;
        esac
    done
    
    compileCode
    echo ""

    counter=1
    while [ $counter -le $n_simulations ]; do
        echo -e "\e[21m\e[58:5:42mSimulation test ${counter}\e[59m\e[24m"
        random_sim_file
        run_versions "$args1" "$args2"
        compare_output
        ((counter++))
        echo "" 
    done
}

main "$@"
