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
        int txtId = f.a___addTextField(99, 10, 30, 100, 50);
        f.a___addButton(100, 10, 50, 100, 70, "magic");
        int slId = f.a___addSlider(99, 10, 80, 100, 100);
        int rID = f.a___addSlider(99, 10, 500, 400, 520);
        int gID = f.a___addSlider(99, 10, 520, 400, 540);
        int bID = f.a___addSlider(99, 10, 540, 400, 560);
        int x = 400;
        int y = 50;
        f.a___setSlider(slId, 200);
        f.a___setSlider(rID, 500);
        f.a___setSlider(gID, 500);
        f.a___setSlider(bID, 500);
        while (true) {
            do {
                System.err.println(f.a___firedEvent());
                switch (f.a___firedEvent()) {
                    case 37: x -= 10; break;
                    case 39: x += 10; break;
                    case 38: y -= 10; break;
                    case 40: y += 10; break;
                    case 100: f.a___setTextField(txtId, "3.141592"); break;
                }
                f.a___erase();
                String txt = f.a___getTextField(txtId);
                f.a___color(f.a___getSlider(rID)/1000.f, f.a___getSlider(gID)/1000.f, f.a___getSlider(bID)/1000.f);
                f.a___disk(x, y, 20);
                f.a___color(1, 1, 1);
                f.a___centeredText(x, y-22, f.a___getSlider(slId)/10.f, txt);
            } while (f.a___waitWithEvent(1000));
            y = y + 10;
            if (f.a___isClosed()) System.exit(0);
        }
    }
    
}
