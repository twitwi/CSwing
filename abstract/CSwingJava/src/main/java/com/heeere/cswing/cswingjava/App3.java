/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.heeere.cswing.cswingjava;

import com.heeere.cswing.A___Fenetre;

/**
 *
 * @author twilight
 */
public class App3 {
    
    public static void main(String[] args) {
        A___Fenetre f = new A___Fenetre();
        f.a___initialize(800, 600);
        f.a___toggleLoopingMode();
        int x = 400;
        int y = 50;
        while (true) {
            do {
                System.err.println(f.a___pressedKey());
                switch (f.a___pressedKey()) {
                    case 37: x -= 10; break;
                    case 39: x += 10; break;
                    case 38: y -= 10; break;
                    case 40: y += 10; break;
                        
                }
                f.a___erase();
                f.a___disk(x, y, 20);
            } while (f.a___waitWithKeyboard(400));
            y = y + 10;
            if (f.a___isClosed()) System.exit(0);
        }
    }
    
}
