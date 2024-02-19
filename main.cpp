// Emma Bilhimer
// Busch SP24
//  ASList-BinarySearch

#include "ASList.h"

ASList::ASList()
{
    length = 0;
    loc = -1;
}

ASList::~ASList()
{
}

void ASList::MakeEmpty()
{
    length = 0;
}

bool ASList::IsFull() const
{
    if(length == MAX_ITEMS)
        return true;
    else
        return false;
}

ItemType ASList::GetItem(ItemType item, bool& found)
{
    found = false;
    
    int index = findItem(item);

    if (index != -1)
    {
        found = true;
        return Items[index];
    }
    else
        return item;
}

void ASList::PutItem(ItemType item)
{
    Items[length] = item;
    length++;
}

void ASList::DeleteItem(ItemType item)
{
    int index = findItem(item);
    if(index != -1)
    {
        while(index < length - 1)
        {
            Items[index] = Items[index + 1];
            index++;
        }
        length--;
    }
}

void ASList::ResetList()
{
    loc = -1;
}

ItemType ASList::GetNextItem()
{
    loc++;
    return Items[loc];
}

//start binary search
int ASList::findItem(ItemType item)
{
    // binary search algorithm implementation
    int low = 0;
    int high = length - 1;          //low & high variables
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (Items[mid].compareTo(item) == RelationType::EQUAL)
            return mid; // item found at mid
        else if (Items[mid].compareTo(item) == RelationType::LESS)
            low = mid + 1; // Discard the left half
        else
            high = mid - 1; // Discard the right half
    }
    return -1; // Item not found
}

/* What I Changed:
  - low and high variables to keep track of the range in which the search is being
 performed.
 - calculated the mid index as the average of low and high.
 - check if the item at the mid index is equal to the search item. if yes, returned the
 mid index indicating that the item is found.
 -  updated low to mid + 1 to search in the right half of the array.
 - if the search item is greater than the item at mid, updated high to mid - 1 to search in
 the left half of the array.
 - if the search completes and the item is not found, returned -1 to indicate that the item
 is not present in the array.*/
