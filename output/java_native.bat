javac -d ../src/ ../android-studio/libspritergm/src/main/java/com/libspritergm/spriterGMNative.java
cd ../src/
javah com.libspritergm.spriterGMNative
rmdir com /s /q
pause