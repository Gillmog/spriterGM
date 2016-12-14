javac -d ../src/ ../src/main/java/com/libspritergm/spriterGMNative.java
cd ../src/
javah com.libspritergm.spriterGMNative
rmdir com /s /q
pause