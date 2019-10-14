/**
 * 二叉搜索树增、删、改的效率：
 * 1、最坏情况：二叉树退化为链表，时间复杂度为O(n)。
 * 2、最好情况：二叉树为完全二叉树，时间复杂度为O(logn)。
 * 总结，时间复杂度的范围(O(logn),O(n))
 * 
 * 针对第2种情况，推导如下：
 * 假设，二叉树的层数为L，则层和该层的节点数目对应关系如下：
 *      1    1
 *      2    2
 *      3    4
 *      4    8
 *      ……   ……
 *      L    2^(L-1)
 * 因为是完全二叉树，故最后一层节点数目有可能不全，故最终的L层
 * 的二叉搜索树的节点数量的范围： 
 *      (1 + 2 + 4 + 8 + …… + 2^(L-2) + 1) <= n <= (1 + 2 + 4 + 8 + …… + 2^(L-1))
 * 根据等比公式，结果： 
 *      2^(L-1) <= n <= 2^L-1 
 * L的范围：
 *      L-1 <= logn
 *      log(n+1) <= L
 * ==>  log(n+1) <= L <= logn+1
 * 
 * 故完全二叉树的查找操作的时间复杂度为 O(logn)。
*/