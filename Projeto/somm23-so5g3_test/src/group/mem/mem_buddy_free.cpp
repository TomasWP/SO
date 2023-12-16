/*
 *  \author Paulo Macedo
 */

#include "pct.h"
#include "somm23.h"

#include <stdint.h>

namespace group 
{

    static MemTreeNode* findNode(MemTreeNode* node, Address address); 
    static void mergeBlocks(MemTreeNode* root);

// ================================================================================== //

    void memBuddySystemFree(Address address)
    {
        soProbe(509, "%s(%u)\n", __func__, address);

        MemTreeNode* node = findNode(memTreeRoot, address);
        
        if (node != NULL && node->state == OCCUPIED){
            node->state = FREE;
            mergeBlocks(memTreeRoot);
        } else {
            throw Exception(EINVAL, __func__); 
        }
    }

// ================================================================================== //
    
    MemTreeNode* findNode(MemTreeNode* node, Address address) {
        if (node == NULL) 
            return NULL;

        if (node->block.address == address && node->state == OCCUPIED) 
            return node;

        MemTreeNode* left = findNode(node->left, address);
        if (left != NULL)
            return left;

        return findNode(node->right, address);
    }

    void mergeBlocks(MemTreeNode* root) {
        if (root == NULL) 
            return;

        mergeBlocks(root->left);
        mergeBlocks(root->right);

        if (root->left != NULL && root->right != NULL && root->left->state == FREE && root->right->state == FREE){
            root->state = FREE;
            free(root->left);
            free(root->right);
            root->left = NULL;
            root->right = NULL;
        }
    }

} // end of namespace group

