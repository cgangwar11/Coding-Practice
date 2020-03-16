package SplitWise.control;

import SplitWise.model.Expense;
import SplitWise.model.Group;
import SplitWise.model.GroupMapping;
import SplitWise.model.Person;


import lombok.Data;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Slf4j @Data
public class Application {

    private List<GroupMapping> mapping;
    private List<Expense> expenseList;
    private List<Person> allUsers;
    private List<Group> allGroups;

    public Application() {
        mapping = new ArrayList<>();
        expenseList = new ArrayList<>();
        allUsers = new ArrayList<>();
        allGroups = new ArrayList<>();
    }

    public boolean addUser(String id,String name){
        allUsers.add(new Person(id,name));
        return true;
    }

    public boolean addExpense(String expenseId,String givenById,String recievedById,Double amount){
        expenseList.add(new Expense(expenseId,amount,givenById,recievedById,false));
        return true;
    }

    public void printAllExpensesById(String personId){
        Optional<Double> owes = expenseList.stream()
                .filter(it -> it.getRecievedBy().equalsIgnoreCase(personId)).map(it -> it.getAmount())
                .reduce((Double a,Double b) -> a+b);
        Optional<Double> due = expenseList.stream()
                .filter(it -> it.getGivenTo().equalsIgnoreCase(personId)).map(it -> it.getAmount())
                .reduce((Double a,Double b) -> a+b);

        log.info("Person with id {} owes {} and has due {}",personId,owes.isPresent() ? owes.get() : 0,due.isPresent() ? due.get() : 0);
    }

    public void splitExpenseEqually(Double amount,String id,String paidBy,String... toBeSplitted){
        Double perPersonSplit = amount/(1+toBeSplitted.length);
        if(toBeSplitted.length == 0) return; //Invalid Entry
        int count = 1;
        for(String user : toBeSplitted){
            expenseList.add(new Expense(id+ "" + count,perPersonSplit,paidBy,user,false));
            count++;
        }
    }













}
