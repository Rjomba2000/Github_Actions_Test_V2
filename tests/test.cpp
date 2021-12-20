#include "../src/MyBinaryTree.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Insert works correctly") {
    MyBinaryTree<int> tree;
    tree.insert(10);
    REQUIRE(tree.find(10));
    tree.insert(1);
    REQUIRE(tree.find(1));
    tree.insert(20);
    REQUIRE(tree.find(20));
}

TEST_CASE("Remove works correctly") {
    MyBinaryTree<int> tree;
    REQUIRE(!tree.find(10));
    tree.remove(10);
    REQUIRE(!tree.find(10));
    tree.insert(10);
    tree.remove(10);
    REQUIRE(!tree.find(10));
    tree.insert(1);
    tree.insert(0);
    tree.insert(2);
    tree.remove(0);
    tree.remove(2);
    REQUIRE(!tree.find(0));
    REQUIRE(!tree.find(2));
}
