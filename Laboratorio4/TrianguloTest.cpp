#include <gtest/gtest.h>
#include "Triangulo.hpp"

//Test Fixture
class TrianguloTest : public ::testing::Test {
protected:
    Triangulo<int> *trianguloEquilatero1;
    Triangulo<int> *trianguloEquilatero2;
    Triangulo<int> *trianguloIsosceles1;
    Triangulo<int> *trianguloIsosceles2;
    Triangulo<int> *trianguloEscaleno1;
    Triangulo<int> *trianguloEscaleno2;
    Triangulo<int> *trianguloInvalido1;
    Triangulo<int> *trianguloInvalido2;

    // SetUp
    void SetUp() override {
        trianguloEquilatero1 = new Triangulo<int>(1, 1, 1);
        trianguloEquilatero2 = new Triangulo<int>(10, 10, 10);
        trianguloIsosceles1 = new Triangulo<int>(3, 4, 4);
        trianguloIsosceles2 = new Triangulo<int>(10, 10, 8);
        trianguloEscaleno1 = new Triangulo<int>(5, 6, 7);
        trianguloEscaleno2 = new Triangulo<int>(5, 6, 7);
        trianguloInvalido1 = new Triangulo<int>(10, 2, 8);
        trianguloInvalido2 = new Triangulo<int>(5, 1, 2);
    }

    //TearDown
    void TearDown() override {
        delete trianguloEquilatero1;
        delete trianguloEquilatero2;
        delete trianguloIsosceles1;
        delete trianguloIsosceles2;
        delete trianguloEscaleno1;
        delete trianguloEscaleno2;
        delete trianguloInvalido1;
        delete trianguloInvalido2;
    }
};

// Pruebas para un triángulo equilátero utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloEquilatero) {
    ASSERT_NE(nullptr, trianguloEquilatero1);
    ASSERT_EQ(trianguloEquilatero1->tipo(),"equilatero");
    ASSERT_NE(nullptr, trianguloEquilatero2);
    ASSERT_EQ(trianguloEquilatero2->tipo(),"equilatero");
}

// Pruebas para un triángulo isósceles utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloIsosceles) {
    ASSERT_NE(nullptr, trianguloIsosceles1);
    ASSERT_EQ(trianguloIsosceles1->tipo(),"isosceles");
    ASSERT_NE(nullptr, trianguloIsosceles2);
    ASSERT_EQ(trianguloIsosceles2->tipo(),"isosceles");
}

// Prueba para un triángulo escaleno utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloEscaleno) {
    ASSERT_NE(nullptr, trianguloEscaleno1);
    ASSERT_EQ(trianguloEscaleno1->tipo(),"escaleno");
    ASSERT_NE(nullptr, trianguloEscaleno2);
    ASSERT_EQ(trianguloEscaleno2->tipo(),"escaleno");
}

// Prueba para un triángulo invalido utilizando el Test Fixture
TEST_F(TrianguloTest, TrianguloInvalido) {
    ASSERT_NE(nullptr, trianguloInvalido1);
    ASSERT_EQ(trianguloInvalido1->tipo(),"invalido");
    ASSERT_NE(nullptr, trianguloInvalido2);
    ASSERT_EQ(trianguloInvalido2->tipo(),"invalido");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
