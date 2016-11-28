///spriter_delete_gm_instance()
var nSpriteInfos = spriter_GetSpriteInfoCount(modelIndex, instanceIndex);

for (i = nSpriteInfos - 1; i >= 0; i--)
{
    inst[i].sprite_index = -1;
    inst[i].deleted=1; 
    sprite_delete(sprite[i]);
}
