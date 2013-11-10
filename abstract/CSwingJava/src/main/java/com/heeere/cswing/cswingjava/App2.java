package com.heeere.cswing.cswingjava;

import com.heeere.cswing.A___Fenetre;

/**
 * Hello world!
 *
 */
public class App2
{
    public static void main( String[] args ) throws InterruptedException {
        A___Fenetre f = new A___Fenetre();
        f.a___initialize(800, 600);
        f.a___toggleLoopingMode();
        
        int t = 0;
        float yy;
        while (true) {
            f.a___erase();
            t++;
            String message = "Hello cswing! ! !";
            int ii;
            //float delta = rand() / (RAND_MAX / 10.);
            //yy += delta;
            yy = (float) (300 + 100*Math.sin(t/10.));
            for (ii = 0; ii<message.length(); ii++) {
                f.a___color( 0, 1, 0);
                String buf = ""+message.charAt(ii);
                
                float i = ii;//+(rand() / (RAND_MAX / 10.));
                float y = yy;
                f.a___text(i*10, y, 10, buf);
                y = y+5;
                f.a___frame( i*10, y, 10+i*10, y+10);
                y = y+25;
                f.a___centeredText(i*10, y, 10, buf);
                y = y+35;
                f.a___color(1, 1, 1);
                f.a___frame(i*30, y-30, 30+i*30, y);
                f.a___centeredText(i*30 + 15, y, 30, buf);
                y = y+35;
                f.a___color(1, 1, 1);
                f.a___frame(i*30, y-30, 30+i*30, y);
                f.a___centeredText(i*30 + 15, y-5, 20, buf);
            }
            f.a___waitFor(10);
            System.err.println(System.currentTimeMillis());
            if (f.a___isClosed()) {
                break;
            }
            //attendreFermeture(f);
        }
        
        
        /*
        while (true) {
        String message = "Hello Java !!!!";
        for (char c : message.toCharArray()) {
        float x = 800*(float) Math.random();
        float y = 600*(float) Math.random();
        f.texteCentre(x, y, 10, ""+c);
        f.texteCentre(x, y+20, 20, ""+c);
        }
        Thread.sleep(10);
        f.effacer();
        }
        */
        
    }
}
