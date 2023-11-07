#include <gtest/gtest.h>
#include "Triangulo.hpp"

//Test Fixture
class TrianguloTest : public ::testing::Test {
protected:
    Triangulo<int> *triangulo1;
    Triangulo<int> *triangulo2;

    // SetUp
    void SetUp() override {
        triangulo1 = nullptr;
        triangulo2 = nullptr;
    }

    //TearDown
    void TearDown() override {
        delete triangulo1;
        delete triangulo2;
    }
};

// Pruebas para un triángulo equilátero utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloEquilatero) {
    triangulo1 = new Triangulo<int>(1, 1, 1);
    triangulo2 = new Triangulo<int>(10, 10, 10);
    ASSERT_NE(nullptr, triangulo1);
    ASSERT_EQ(triangulo1->tipo(),"equilatero");
    ASSERT_NE(nullptr, triangulo2);
    ASSERT_EQ(triangulo2->tipo(),"equilatero");
}

// Pruebas para un triángulo isósceles utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloIsosceles) {
    triangulo1 = new Triangulo<int>(3, 4, 4);
    triangulo2 = new Triangulo<int>(10, 10, 8);
    ASSERT_NE(nullptr, triangulo1);
    ASSERT_EQ(triangulo1->tipo(),"isosceles");
    ASSERT_NE(nullptr, triangulo2);
    ASSERT_EQ(triangulo2->tipo(),"isosceles");
}

// Prueba para un triángulo escaleno utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloEscaleno) {
    triangulo1 = new Triangulo<int>(5, 6, 7);
    triangulo2 = new Triangulo<int>(10, 11, 12);
    ASSERT_NE(nullptr, triangulo1);
    ASSERT_EQ(triangulo1->tipo(),"escaleno");
    ASSERT_NE(nullptr, triangulo2);
    ASSERT_EQ(triangulo2->tipo(),"escaleno");
}

// Prueba para un triángulo invalido utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloInvalido) {
    triangulo1 = new Triangulo<int>(10, 2, 8);
    triangulo2 = new Triangulo<int>(5, 1, 2);
    ASSERT_NE(nullptr, triangulo1);
    ASSERT_EQ(triangulo1->tipo(),"invalido");
    ASSERT_NE(nullptr, triangulo2);
    ASSERT_EQ(triangulo2->tipo(),"invalido");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
