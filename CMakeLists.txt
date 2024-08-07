cmake_minimum_required(VERSION 3.24)
project(master_exam)

set(CMAKE_CXX_STANDARD 11)

add_executable(StructDemo basic/StructDemo.c)
add_executable(QuoteDemo basic/QuoteDemo.cpp)
add_executable(LNodeDetails SeqList/LNodeDetails.cpp)
add_executable(Array SeqList/Array.cpp)
add_executable(SeqStack stackandqueue/SeqStack.cpp)
add_executable(LinkedStack stackandqueue/LinkedStack.cpp)
add_executable(SeqQueue stackandqueue/SeqQueue.cpp)
add_executable(LinkedQueue stackandqueue/LinkedQueue.cpp)
add_executable(BinaryTree tree/BinaryTree.cpp tree/BinaryTree.h)
add_executable(ExerciseForBinaryTree tree/Ex6_1.cpp)
add_executable(Ex6_2 tree/Ex6_2.cpp)
add_executable(Ex6_3 tree/Ex6_3.cpp)
add_executable(Ex6_4 tree/Ex6_4.cpp)
add_executable(Ex6_5 tree/Ex6_5.cpp)
add_executable(ThreadedBinaryTree tree/ThreadedBinaryTree.cpp)
add_executable(HuffmanTree tree/HuffmanTree.cpp)
add_executable(Sort sort/Sort.cpp)
add_executable(TestSwap basic/TestSwap.c)
add_executable(TestPointer basic/TestPointer.c)

add_executable(TopSort graph/TopSort.cpp)
add_executable(Prim graph/Prim.cpp)
add_executable(Tree leetcode/tree/Tree.cpp)
add_executable(LinkedList leetcode/tree/LinkedList.cpp)
add_executable(LNodeForCaculate seqList/LNodeForCaculate.cpp)
add_executable(Polynode seqList/Polynode.cpp)

add_executable(PriorityQueue stackandqueue/PriorityQueue.cpp)
add_executable(MatchByStack stackandqueue/MatchByStack.cpp)
add_executable(CaculateByStack stackandqueue/CalculateByStack.cpp)
add_executable(UninoFindSet tree/UninoFindSet.cpp)
add_executable(BFS graph/BFS.cpp)
add_executable(DFS graph/DFS.cpp)
add_executable(Kruskal graph/Kruskal.cpp)
add_executable(Dijkstra graph/Dijkstra.cpp)
add_executable(Floyd graph/Floyd.cpp)
add_executable(BinarySearchTree search/BinarySearchTree.cpp)
add_executable(BinarySearch search/BinarySearch.cpp)
add_executable(TestQuote basic/TestQuote.cpp)