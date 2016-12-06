package com.libspritergm;

/**
 * Created by Gillmog on 06.12.2016.
 */

public class spriterGMNative {
    static
    {
        System.loadLibrary("spriterGM");

    }

    native public static double spriter_LoadModel(String file);
}
