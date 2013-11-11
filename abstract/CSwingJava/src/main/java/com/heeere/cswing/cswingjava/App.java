package com.heeere.cswing.cswingjava;

import com.heeere.cswing.A___Fenetre;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) {
        A___Fenetre f = new A___Fenetre();
        f.a___initialize(800, 600);
        A___Fenetre f2 = new A___Fenetre();
        f2.a___initialize(200, 300);
        
        f.a___color(1,0,0);
        f.a___circle(100,200,50);
        
        f2.a___color(0,0,1);
        f2.a___circle(100,200,50);
        f2.a___erase();
        f2.a___color(0, 1, 1);
        f2.a___line(10, 20, 100, 20);
        
        f2.a___text(10, 20, 20, "Hello man!");
        f2.a___text(10, 40, 20, "WWW");
        f2.a___centeredText(10, 60, 20, "WWW");
        f2.a___centeredText(10, 80, 20, "W");

        f2.a___text(10, 100, 10, "WWW");
        f2.a___centeredText(10, 110, 10, "WWW");
        f2.a___centeredText(10, 120, 10, "W");

        f2.a___text(10, 160, 40, "WWW");
        f2.a___centeredText(10, 200, 40, "WWW");
        f2.a___centeredText(10, 240, 40, "W");

        f2.a___centeredText(100, 300, 100, "C");

        f2.a___color(1, 0, 0);
        f2.a___line(10, 0, 10, 500);
        
        f.a___waitClosing();
        f2.a___waitClosing();
        System.exit(0);
       
    }
}
