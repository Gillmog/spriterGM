///spriter_get_box_point_x(object, object_index, point_name)
var mesh_index = -1;

switch(argument2)
{
    case "TopLeft":
    mesh_index = 0;
    break;
    case "TopRight":
    mesh_index = 1;
    break;
    case "BottomRight":
    mesh_index = 2;
    break;
    case "BottomLeft":
    mesh_index = 3;
    break;
    default:
    return undefined;
}
var px = spriter_GetObjectInfoMeshPointX(argument0.modelIndex, argument0.instanceIndex, argument1, mesh_index);
spriter_check_errors();
return px;
