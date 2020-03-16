package SplitWise.model;

import lombok.Data;

@Data
public class Person {


    private String name;
    private String email;
    private String id;

    public Person(String id,String name){
        name = name;
        id = id;
    }



}
