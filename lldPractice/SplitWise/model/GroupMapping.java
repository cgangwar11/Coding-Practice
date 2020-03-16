package SplitWise.model;

import lombok.Data;
// Many to many relation
@Data
public class GroupMapping {
    private String groupId;
    private String personId;
    private String mappingId;
}
