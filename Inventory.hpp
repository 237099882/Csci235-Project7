/*
CSCI235 Fall 2023
Project 7 - Trinkets and Baubles: The Inventory 
zhilin li
*/
#ifndef INVENTORY_HPP
#define INVENTORy_HPP

#include <iostream>
#include "BinarySearchTree.hpp"
#include "Item.hpp"
#include <vector>
#include <algorithm>

class Inventory : public BinarySearchTree<Item*>
{
public:
    Inventory();
    /**
     * @param : A Pointer to the Item object to be added to the inventory.
     * @post  : The Item is added to the inventory, preserving the BST structure. The BST property is based on (ascending) alphabetical order of the item's name.
     *          If the item is type UNKNOWN, WEAPON, or ARMOR and is already in the inventory, it is not added.
         However, if another instance of an Item of type CONSUMABLE is being added (an item with the same name), its quantity is updated to the sum of the quantities of the two objects, and the time_picked_up_ variable is updated to that of the latest instance of the item being added.
    * @return true if the item was added to the inventory or updated, false otherwise.
    */
    bool addItem(Item* item);
    /**
     * @param   : A reference to string name of the item to be found.
     * @return  : An Item pointer to the found item, or nullptr if the item is not in the inventory.
     */
    Item* findItem(const std::string& item) const;
    /**
     * @param   : A reference to string name of the item to be removed from the inventory.
     * @return  : True if the item was found and removed or updated successfully, false otherwise.
     * @post    : If the item is found in the inventory, it is removed while preserving the BST structure.
                 If a CONSUMABLE is removed, its quantity is decremented by one, but its time_picked_up_ remains the same. However, if it is the last item (it's quantity is 1 and is being removed), the item should be removed. Non-CONSUMABLE items should always be removed when they are found.
    */
    bool removeItem(const std::string& item);
    /**
     * @return    : The total sum of gold values of all items in the inventory.
     */
    int getTotalGoldValue();
    /**
     * @post    : The names of all items in the Inventory are printed in ascending order.
     *            This function performs an in-order traversal of the binary search tree and prints the details of each item in the following format. 
            NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS.

    *            [NAME] ([TYPE])
                Level: [LEVEL]
                Value: [VALUE]
                Quantity: [QUANTITY]
    
                Example:
                TIRED GAUNTLETS (ARMOR)
                Level: 3
                Value: 25
            
                SMALL HEALTH POTION (CONSUMABLE)
                Level: 1
                Value: 10
                Quantity: 2
    * 
    */
    void printInventoryInOrder() const;
    /**
     * @param   : a reference to bool if the items are to be printed in ascending order. 
     * @param   : a reference to string attribute which defines the order by which the items are to be printed. You may assume that the given parameter will be in one of the following forms: ["NAME"/"TYPE"/"LEVEL"/"VALUE"/"TIME"]
     * @post    : All items in the Inventory are printed in the order specified by the parameter.
     *          Example usage: inventory.printInventory(false, "LEVEL");
                NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS:

                FEATHER DUSTER (WEAPON)
                Level: 5
                Value: 100

                TIRED GAUNTLETS (ARMOR)
                Level: 3
                Value: 50

                SMALL HEALTH POTION (CONSUMABLE)
                Level: 1
                Value: 10
                Quantity: 2

                NOODLES (CONSUMABLE)
                Level: 0
                Value: 120
                Quantity: 5
    */
    void printInventory(const bool& order, const std::string& attribute);
    //helper function to get total gold value
    int getSubtreeTotal(std::shared_ptr<BinaryNode<Item*>> subTreePtr);
    //helper funtion to print
    void printInfo(std::shared_ptr<BinaryNode<Item*>> subTreePtr) const;
    void printInfo(Item* item) const;
    void printNode(std::shared_ptr<BinaryNode<Item*>> subTreePtr) const;
    std::vector<Item*> createVector(std::shared_ptr<BinaryNode<Item*>> subTreePtr,std::vector<Item*> sorted);
    std::vector<Item*> sortVector(const bool& order, const std::string& attribute,std::vector<Item*> sorted);
};

#endif