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
        f.a___addButton(38, 10, 10, 100, 30, "up");
        int txtId = f.a___addTextField(10, 30, 100, 50);
        f.a___addButton(100, 10, 50, 100, 70, "magic");
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
                    case 100: f.a___setTextField(txtId, "3.141592");
                        
                }
                f.a___erase();
                String txt = f.a___getTextField(txtId);
                f.a___disk(x, y, 20);
                f.a___centeredText(x, y-20, 10, txt);
            } while (f.a___waitWithKeyboard(1000));
            y = y + 10;
            if (f.a___isClosed()) System.exit(0);
        }
    }
    
}
