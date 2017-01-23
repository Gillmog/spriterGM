///spriter_is_trigger(object, trigger_name)
for (var i = 0; i < spriter_InstanceGetTriggerInfoCount(argument0.modelIndex, argument0.instanceIndex); i++)
{
    var name = spriter_InstanceGetTriggerInfoName(argument0.modelIndex, argument0.instanceIndex, i);
    
    if argument1 == name
    {
        return true;
    }
}

return false;
