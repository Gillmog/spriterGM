package com.libspritergm;

/**
 * Created by Gillmog on 06.12.2016.
 */

public class spriterGM {
    public double spriter_LoadModel(String file)
    {
        return spriterGMNative.spriter_LoadModel(file);
    }
}
