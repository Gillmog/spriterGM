///spriter_find_object(object, name)
var nObjectInfo = spriter_GetObjectInfoCount(argument0.modelIndex, argument0.instanceIndex);
spriter_check_errors();
for (var i = 0; i < nObjectInfo; i++)
{
    var name = spriter_GetObjectInfoName(argument0.modelIndex, argument0.instanceIndex, i);
    
    if name == argument1
    {
        return i;
    }
}

return -1;
