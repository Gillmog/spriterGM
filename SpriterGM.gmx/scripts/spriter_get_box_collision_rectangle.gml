///spriter_get_box_collision_rectangle(object, object_check, box_name)
var box_index = spriter_find_object(argument0, argument2);

if box_index != -1
{
    var tlx = spriter_get_box_point_x(argument0, box_index, "TopLeft");
    var tly = spriter_get_box_point_y(argument0, box_index, "TopLeft");
    var tbrx = spriter_get_box_point_x(argument0, box_index, "BottomRight");
    var tbry = spriter_get_box_point_y(argument0, box_index, "BottomRight");
    
    return collision_rectangle(tlx, tly, tbrx, tbry, argument1, false, true);
}

return undefined;
