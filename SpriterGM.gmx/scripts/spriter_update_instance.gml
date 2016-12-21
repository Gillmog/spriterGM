///spriter_update_instance()
var elapsedTime =  current_time - startTime;

spriter_set_instance_angle(degtorad(image_angle));

spriter_set_instance_scale(image_xscale, image_yscale);

spriter_set_instance_position(x + sprite_width * 0.5, y + sprite_height * 0.5);

spriter_UpdateInstance(modelIndex, instanceIndex, elapsedTime);

spriter_check_errors();

var nTriggerCount = spriter_instance_get_trigger_count();
var nSoundCount = spriter_instance_get_sound_count();

for (i = nTriggerCount - 1; i >= 0; i--)
{
    var triggerName = spriter_instance_get_trigger_name(i);
    spriter_trigger_callback(self, triggerName);
}

for (i = nSoundCount - 1; i >= 0; i--)
{
    var soundName = spriter_instance_get_sound_name(i);
    spriter_sound_callback(self, soundName);
}

startTime = current_time;

