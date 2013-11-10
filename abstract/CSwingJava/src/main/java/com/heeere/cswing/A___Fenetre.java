package com.heeere.cswing;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 */
public class A___Fenetre {

    JFrame f;
    BufferedImage a___backBuffer = null;
    BufferedImage a___displayBuffer = null;
    Color a___currentColor = Color.WHITE;
    
    public void a___initialize(int w, int h) {
        a___backBuffer = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
        f = new JFrame("Window");
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setResizable(false);
        f.setContentPane(new JLabel(new ImageIcon(a___backBuffer)));
        f.pack();
        f.setVisible(true);
    }
    
    public void a___erase() {
        Graphics2D g = a___backBuffer.createGraphics();
        g.clearRect(0, 0, a___backBuffer.getWidth(), a___backBuffer.getHeight());
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___color(float r, float g, float b) {
        a___currentColor = new Color(r, g, b);
    }
    
    public void a___circle(float cx, float cy, float r) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        g.draw(new Ellipse2D.Float(cx - r, cy -r, 2*r, 2*r));
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___disk(float cx, float cy, float r) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setPaint(a___currentColor);
        g.fill(new Ellipse2D.Float(cx - r, cy -r, 2*r, 2*r));
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___line(float x1, float y1, float x2, float y2) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        g.draw(new Line2D.Float(x1, y1, x2, y2));
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___frame(float x1, float y1, float x2, float y2) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        g.setStroke(new BasicStroke(1f));
        g.draw(new Rectangle2D.Float(x1, y1, x2-x1, y2-y1));
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___rectangle(float x1, float y1, float x2, float y2) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        g.fill(new Rectangle2D.Float(x1, y1, x2-x1, y2-y1));
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___text(float a___left, float a___bottom, float a___size, String txt) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        g.translate(a___left, a___bottom);
        g.scale(a___size/10, a___size/10);
        g.drawString(txt, 0, 0);
        g.dispose();
        a___maybeRepaint();
    }

    public void a___centeredText(float a___center, float a___bottom, float a___size, String txt) {
        Graphics2D g = a___backBuffer.createGraphics();
        g.setColor(a___currentColor);
        FontMetrics fm = g.getFontMetrics();
        g.translate(a___center - fm.stringWidth(txt)*a___size/10./2., a___bottom);
        g.scale(a___size/10, a___size/10);
        g.drawString(txt, 0, 0);
        g.dispose();
        a___maybeRepaint();
    }
    
    public void a___exportImage(String a___fileName) {
        BufferedImage a___output = new BufferedImage(a___backBuffer.getWidth(), a___backBuffer.getHeight(), a___backBuffer.getType());
        Color a___bgColor = Color.BLUE.darker().darker();
        Color a___borderColor = Color.WHITE;
        Color a___textColor = Color.WHITE;
        Graphics2D g = a___output.createGraphics();
        g.drawImage(a___backBuffer, 0, 0, null);
        g.setColor(a___bgColor);
        g.fillRect(0, 0, 250, 30);
        { // draw info
            String s = "file:" + a___fileName;
            g.setColor(a___textColor);
            g.drawString(s, 10, 20);
        }
        g.setColor(a___borderColor);
        g.drawRect(0, 0, 250, 30);
        String ext = null;
        try {
            ext = a___fileName.replaceFirst("^.*[.]", "");
            ImageIO.write(a___output, ext, new File(a___fileName));
        } catch (IOException ex) {
            System.out.println(String.format("Error while saving file '%s' (format %s)\n %s\n", a___fileName, ext, ex.getMessage()));
        }
    }
    
    public Long a___previousWait = null;
    public void a___waitFor(int ms) {
        if (!a___loopingMode) {
            try {
                Thread.sleep(ms);
            } catch (InterruptedException ex) {
                Logger.getLogger(A___Fenetre.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            a___displayBuffer.createGraphics().drawImage(a___backBuffer, 0, 0, null);
            f.repaint();
            long now = System.currentTimeMillis();
            if (a___previousWait == null) {
                a___previousWait = now - ms;
            }
            long towait = (a___previousWait + ms) - now;
            a___previousWait += ms;
            if (towait > 0) {
                try {
                    Thread.sleep(towait);
                } catch (InterruptedException ex) {
                    Logger.getLogger(A___Fenetre.class.getName()).log(Level.SEVERE, null, ex);
                }                
            }
        }
    }

    private BlockingQueue<Integer> a___queue = new ArrayBlockingQueue<Integer>(1000);
    public Long a___nextFireInstant = null;
    public boolean a___waitWithKeyboard(int ms) {
        if (!a___loopingMode) {
            throw new IllegalStateException();
        }
        a___displayBuffer.createGraphics().drawImage(a___backBuffer, 0, 0, null);
        f.repaint();
        long now = System.currentTimeMillis();
        // this is the very first call
        if (a___previousWait == null) {
            a___previousWait = now - ms;
        }
        // this is an initial call (not a continuation after a key stroke
        if (a___nextFireInstant == null) {
            a___nextFireInstant = a___previousWait + ms;
            a___previousWait += ms;
        }
        // get or wait
        long towait = a___nextFireInstant - now;
        try {
            a___lastKeyPress = a___queue.poll(towait, TimeUnit.MILLISECONDS);
            if (a___lastKeyPress == null) {
                a___nextFireInstant = null;
            }
            return a___lastKeyPress != null;
        } catch (InterruptedException ex) {
            Logger.getLogger(A___Fenetre.class.getName()).log(Level.SEVERE, null, ex);
        }
        // interruption (not a normal case...)
        a___lastKeyPress = null;
        return false;
    }
    private Integer a___lastKeyPress = null;
    public int a___pressedKey() {
        if (!a___loopingMode) {
            throw new IllegalStateException();
        }
        if (a___lastKeyPress == null) {
            return -111;
        }
        return a___lastKeyPress;
    }

    public void a___waitClosing() {
        // dirty active waiting…
        try {
            while (f.isVisible()) {
                Thread.sleep(200);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(A___Fenetre.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private boolean a___loopingMode = false;
    public void a___toggleLoopingMode() {
        a___loopingMode = !a___loopingMode;
        if (a___displayBuffer == null) { // first time we switch to the looping mode
            a___displayBuffer = new BufferedImage(a___backBuffer.getWidth(), a___backBuffer.getHeight(), a___backBuffer.getType());
            f.addKeyListener(new KeyAdapter() {

                @Override
                public void keyPressed(KeyEvent e) {
                    a___queue.add(e.getKeyCode());
                }
                
            });
        }
        f.setContentPane(new JLabel(new ImageIcon(a___loopingMode ? a___displayBuffer : a___backBuffer)));
    }
    
    private void a___maybeRepaint() {
        if (!a___loopingMode) {
            f.repaint();
        }
    }

    public boolean a___isClosed() {
        return !f.isVisible();
    }

    public void a___close() {
        f.setVisible(false);
        f.dispose();
    }

}
