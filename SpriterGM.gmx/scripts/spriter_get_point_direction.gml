///spriter_get_point_direction(object, point_name)

var point_index = spriter_find_object(argument0, argument1);

if point_index != -1
{
    var x1 = spriter_get_point_x1(argument0, point_index);
    var x2 = spriter_get_point_x2(argument0, point_index);
    var y1 = spriter_get_point_y1(argument0, point_index);
    var y2 = spriter_get_point_y2(argument0, point_index);
    
     return point_direction(x1, y1, x2, y2);
}

return undefined;
    
