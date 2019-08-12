#ifndef DATA_STRUCTURES_LINKLIST_CYCLEDOUBLELINKLIST_CYCLEDOUBLELINKLISTNODE_HPP
#define DATA_STRUCTURES_LINKLIST_CYCLEDOUBLELINKLIST_CYCLEDOUBLELINKLISTNODE_HPP

template<typename T>
class CycleDoubleLinkListNode
{
public:
    T *data;
    CycleDoubleLinkListNode *next;
    CycleDoubleLinkListNode *prev;
};

#endif