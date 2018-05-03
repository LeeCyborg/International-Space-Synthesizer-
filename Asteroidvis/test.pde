Table table;
Asteroid[] asteroids;
int count;
int unit = 40;
int d = 100;
float xoff = 0.0;
int r = 200;
void setup() {
  size(1800, 800);
  ellipseMode(CENTER); 
  table = loadTable("test.csv", "header");
  count = table.getRowCount();
  asteroids = new Asteroid[count];
  background(0);
  assign();

linear();
//circular();
}
void linear(){ 
  int index = 0;
  for (int i = 0; i < width; i+=60) {
    for (int j = 0; j < height; j +=100) {
      if(asteroids[index].danger==false){
        fill(0, 255, 0);
        xoff = xoff + .01;
       float n = noise(xoff)+j;
      ellipse(i+asteroids[index].distance*2, n, asteroids[index].size, asteroids[index].size);
      asteroids[index].x = i; 
      asteroids[index].y = j; 
      } else { 
        fill(255, 0, 0);
       ellipse(i+asteroids[index].distance*2, j, asteroids[index].size, asteroids[index].size);
        println("MEOW");
      }
      index++;
    }
  }
}
void circular(){for (int i = 0; i < 100; i++) {
    //stroke(255, 255, 0); 
    pushMatrix();
    translate(width/2, height/2);
    rotate(radians(10));
    int x = asteroids[i].size;
    float y = asteroids[i].distance;
    xoff = xoff + .01;
       float n = noise(xoff) * width;
    int xP = (int)(y+r*cos(n));
    int yP = (int)(y+r*sin(n));
    ellipse(xP, yP, x, x);
    popMatrix();
  }
}

public class Asteroid {
  public float distance;
  public int size;
  public boolean danger;
  public int x;
  public int y; 
  Asteroid(float dist, int sz, boolean dang) {
    distance=map(dist, 0, 10000, 0, 100);
    size= int(map(sz, 0, 1000, 0, 80));
    danger=dang;
  }
}
void assign() {
  int count = 0;
  for (TableRow row : table.rows()) {
    asteroids[count] = new Asteroid(float(row.getString("Distance")), int(row.getString("Size")), boolean(row.getString("Danger")));
   println(asteroids[count].danger);
    count++;
  }
}
void draw() {
}