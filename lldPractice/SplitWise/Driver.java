package SplitWise;

import SplitWise.control.Application;

public class Driver {

    Application application;

    public static void main(String[] args) {
        Driver driver = new Driver();
        driver.application = new Application();
        driver.application.addUser("u1","Chandan");
        driver.application.addUser("u2","Mahira");
        driver.application.addUser("u3","Rashmi");
        driver.application.addUser("u4","Siddhart");
        driver.application.addUser("u5","Paras");
        driver.application.addExpense("e1","u1","u2",100.0);
        driver.application.addExpense("e1","u1","u2",100.0);
        driver.application.addExpense("e1","u1","u2",100.0);
        driver.application.addExpense("e1","u1","u2",100.0);
        driver.application.getExpenseList();
        driver.application.printAllExpensesById("u1");
        driver.application.splitExpenseEqually(1000.0,"e2","u1","u2","u3","u4");
        driver.application.printAllExpensesById("u2");
        driver.application.printAllExpensesById("u2");

    }
}
