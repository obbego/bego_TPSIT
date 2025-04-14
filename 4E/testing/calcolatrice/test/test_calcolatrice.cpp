#include <gtest/gtest.h>

extern "C" {
    #include "calcolatrice.h"
}

TEST(CalcolatriceTest, Somma) {
    EXPECT_DOUBLE_EQ(somma(2.0, 3.0), 5.0);
}

TEST(CalcolatriceTest, DivisioneByZero) {
    EXPECT_DOUBLE_EQ(divisione(10.0, 0.0), 0.0);  // gestione errore
}

TEST(CalcolatriceTest, RadiceNegativa) {
    EXPECT_DOUBLE_EQ(radice(-9.0), 0.0);  // gestione errore
}
