package org.qtproject.example.test;

public class AndroidJniMethod extends org.qtproject.qt5.android.bindings.QtActivity {
    public AndroidJniMethod() {
    }

    public static void test(String msg) {
        System.out.println(msg);
        System.out.println("Hello World from Android!");
    }

}
