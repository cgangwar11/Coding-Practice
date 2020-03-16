package SplitWise.model;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data @AllArgsConstructor
public class Expense {
    private String expenseId;
    private Double amount;
    private String givenTo;
    private String recievedBy;
    private boolean settled;
}
