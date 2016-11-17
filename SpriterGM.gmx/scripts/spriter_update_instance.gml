var elapsedTime =  current_time - startTime;

spriter_set_instance_angle(degtorad(spriter_angle));

spriter_set_instance_scale(image_xscale, image_yscale);

spriter_set_instance_position(x + sprite_width * 0.5, y + sprite_height * 0.5);

spriter_UpdateInstance(modelIndex, instanceIndex, elapsedTime);

spriter_render_instance();

var nSpriteInfos = spriter_get_instance_sprite_count();


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

if instCount != nSpriteInfos
{
    if instCount < nSpriteInfos
    {
        inst[nSpriteInfos - 1] = instance_create(0, 0, spriterModel_instance);
        sprite_names[SpriteInfos - 1] = "empty_name";
    }
}


for (i = instCount - 1; i >= 0; i--)
{
    inst[i].visible = 0;
}

for (i = nSpriteInfos - 1; i >= 0; i--)
{
    var spriteName = spriter_get_instance_sprite_name(i);
    var scaleX = spriter_get_instance_sprite_xscale(i);
    var scaleY = spriter_get_instance_sprite_yscale(i);
    var angle = spriter_get_instance_sprite_angle(i);
    var isRender = spriter_get_instance_sprite_visible(i);
    
    inst[i].visible = isRender;
    
    if sprite[i] != -1
    {
        var currentSpriteName = sprite_names[i];
        
        if currentSpriteName != spriteName
        {
            sprite_names[i] = spriteName;
            sprite_delete(sprite[i]);
            sprite[i] = sprite_add(imagePath + sprite_names[i],1,0,0,0,0);
            inst[i].sprite_index = sprite[i];
        }
         
        inst[i].image_xscale = scaleX;
        inst[i].image_yscale = scaleY;
        inst[i].image_angle = radtodeg(angle);
        
        spriter_set_instance_sprite_width(i, inst[i].sprite_width / scaleX);
        spriter_set_instance_sprite_height(i, inst[i].sprite_height / scaleY);
    
        var inst_x = spriter_get_instance_sprite_render_xposition(i);
        var inst_y =  spriter_get_instance_sprite_render_yposition(i);
        
        inst[i].x = inst_x;
        inst[i].y = inst_y;
       
        sprite_set_offset(sprite[i], inst[i].sprite_width / scaleX * 0.5, inst[i].sprite_height / scaleY * 0.5);
    }
}

startTime = current_time;


