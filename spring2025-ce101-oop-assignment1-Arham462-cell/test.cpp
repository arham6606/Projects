#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Initialize inventory with a size of 3") {
    Inventory inv;
    int size = 3;
    initializeInventory(inv, size);

    REQUIRE(inv.size == size);
    REQUIRE(inv.currentCount == 0);
    REQUIRE(inv.products != nullptr);
}

TEST_CASE("Add a single product to an empty inventory") {
    Inventory inv;
    int size = 3;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product;
    setProductData(product, supplier, "Book", 19.99);

    int result = addProductToInventory(inv, product);

    REQUIRE(result == 0); // Successfully added
    REQUIRE(inv.currentCount == 1);
    REQUIRE(inv.products[0].productName == "Book");
}

TEST_CASE("Search product by name") {
    Inventory inv;
    int size = 3;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product;
    setProductData(product, supplier, "Book", 19.99);

    addProductToInventory(inv, product);

    Supplier* foundSupplier = searchProductByName(inv, "Book");

    REQUIRE(foundSupplier != nullptr);
    REQUIRE(foundSupplier->supplierName == "ABC Supplies");
    REQUIRE(foundSupplier->contactNumber == "123-456-7890");
}

TEST_CASE("Display inventory with a single product") {
    Inventory inv;
    int size = 3;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product;
    setProductData(product, supplier, "Book", 19.99);

    addProductToInventory(inv, product);

    // Expected to output one product to console, but we won't validate output in the test case
    REQUIRE(inv.currentCount == 1);
}

TEST_CASE("Add two products to inventory and check size") {
    Inventory inv;
    int size = 3;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product1, product2;
    setProductData(product1, supplier, "Book", 19.99);
    setProductData(product2, supplier, "Pen", 1.99);

    addProductToInventory(inv, product1);
    addProductToInventory(inv, product2);

    REQUIRE(inv.currentCount == 2);
}
