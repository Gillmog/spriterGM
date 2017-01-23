///spriter_update(object)
var object = argument0;

var elapsedTime =  current_time - object.startTime;
spriter_SetInstancePosition(object.modelIndex, object.instanceIndex, object.x, object.y);
spriter_SetInstanceScale(object.modelIndex, object.instanceIndex, object.image_xscale, object.image_yscale);
spriter_SetInstanceAngle(object.modelIndex, object.instanceIndex, degtorad(object.image_angle));

spriter_UpdateInstance(object.modelIndex, object.instanceIndex, elapsedTime);

var nSoundCount = spriter_InstanceGetSoundInfoCount(object.modelIndex, object.instanceIndex);

for (i = nSoundCount - 1; i >= 0; i--)
{
    var soundName = spriter_InstanceGetSoundInfoName(object.modelIndex, object.instanceIndex, i);
    
    if audio_exists(soundName)
    {
        audio_play_sound(soundName, 10, 0);
    }
}

object.startTime = current_time;
spriter_check_errors();

