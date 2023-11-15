package com.lab05;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import junit.framework.TestCase;

public class AppTest extends TestCase {
    private WebDriver driver;

    @Override
    protected void setUp() {
        System.setProperty("webdriver.chrome.driver", "src/test/java/com/lab05/chromedriver-linux64/chromedriver");
        driver = new ChromeDriver();
    }

    public void testValidCases(){
        String[][] CasosValidos = {
            {"25.5", "10.2", "2.601"},
            {"-0.02", "9.5", "-0.0019"},
            {"0", "100", "0"},
        };
        System.out.println("Casos Validos: ");
        for (String[] testCase : CasosValidos){
            String result = AppWebdriver.calculatePercentage(driver, testCase[0], testCase[1]);
            System.out.println("Para " + testCase[0] + " y " + testCase[1] + ", el resultado es: " + result);
            assertEquals(testCase[2], result.trim());
        }
    }

    public void testInvalidCases(){
        String[][] CasosInvalidos = {
            {"xyz", "3.1", "Please provide two numeric values in any fields below."},
            {"3.1", "abc", "Please provide two numeric values in any fields below."},
            {"15.5.2", "3.1", "Please provide two numeric values in any fields below."},
            {"100", "", "Please provide two numeric values in any fields below."},
        };
        System.out.println("Casos Invalidos: ");
        for (String[] testCase : CasosInvalidos){
            String result = AppWebdriver.calculatePercentageWrong(driver, testCase[0], testCase[1]);
            System.out.println("Para " + testCase[0] + " y " + testCase[1] + ", el resultado es: " + result);
            assertEquals(testCase[2], result.trim());
        }
    }
    @Override
    protected void tearDown() {
        if (driver != null) {
            driver.quit();
        }
    }
}
