#ifndef DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLISTNODE_HPP
#define DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLISTNODE_HPP

template<typename T>
class DoubleLinkListNode
{
public:
    T *data;
    DoubleLinkListNode *next;
    DoubleLinkListNode *prev;
};

#endif