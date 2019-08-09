#ifndef DATA_STRUCTURES_LINKLIST_SINGLELINKLISTNODE_SINGLELINKLISTNODE_HPP_
#define DATA_STRUCTURES_LINKLIST_SINGLELINKLISTNODE_SINGLELINKLISTNODE_HPP_

template<typename T>
class SingleLinkListNode
{
public:
    T *data;
    SingleLinkListNode *next;
};

#endif