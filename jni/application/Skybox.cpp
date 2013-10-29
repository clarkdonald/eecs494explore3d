#include "Skybox.h"

using namespace Zeni;

void render_skybox(const Camera& camera)
{
  Video &vr = get_Video();
  Material material("sky");

  vr.set_3d(camera);

  Point3f position = camera.position + Vector3f(1000.0f, -1000.0f, 0.0f);

  Vertex3f_Texture p0(position, Point2f(0.0f, 0.0f));
  Vertex3f_Texture p1(position + Vector3f(0.0f, 0.0f, 2000.0f), Point2f(0.0f, 1.0f));
  Vertex3f_Texture p2(position + Vector3f(0.0f, 2000.0f, 0.0f) + Vector3f(0.0f, 0.0f, 2000.0f), Point2f(1.0f, 1.0f)); 
  Vertex3f_Texture p3(position + Vector3f(0.0f, 2000.0f, 0.0f), Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad1(p0, p1, p2, p3);

  p0 = Vertex3f_Texture(position,	Point2f(0.0f, 0.0f));
  p1 = Vertex3f_Texture(position + Vector3f(0.0f, 0.0f, 2000.0f),	Point2f(0.0f, 1.0f));
  p2 = Vertex3f_Texture(position + Vector3f(-2000.0f, 0.0f, 0.0f) + Vector3f(0.0f, 0.0f, 2000.0f), Point2f(1.0f, 1.0f)); 
  p3 = Vertex3f_Texture(position + Vector3f(-2000.0f, 0.0f, 0.0f), Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad2(p0, p1, p2, p3);

  position = camera.position + Vector3f(-1000.0, 1000.0, 0.0f);

  p0 = Vertex3f_Texture(position,	Point2f(0.0f, 0.0f));
  p1 = Vertex3f_Texture(position + Vector3f(0.0f, 0.0f, 2000.0f),	Point2f(0.0f, 1.0f));
  p2 = Vertex3f_Texture(position + Vector3f(2000.0f, 0.0f, 0.0f) + Vector3f(0.0f, 0.0f, 2000.0f), Point2f(1.0f, 1.0f)); 
  p3 = Vertex3f_Texture(position + Vector3f(2000.0f, 0.0f, 0.0f),	Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad3(p0, p1, p2, p3);
  
  p0 = Vertex3f_Texture(position,	Point2f(0.0f, 0.0f));
  p1 = Vertex3f_Texture(position + Vector3f(0.0f, 0.0f, 2000.0f),	Point2f(0.0f, 1.0f));
  p2 = Vertex3f_Texture(position + Vector3f(0.0f, -2000.0f, 0.0f) + Vector3f(0.0f, 0.0f, 2000.0f), Point2f(1.0f, 1.0f)); 
  p3 = Vertex3f_Texture(position + Vector3f(0.0f, -2000.0f, 0.0f), Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad4(p0, p1, p2, p3);
  
  position = camera.position + Vector3f(-1000.0, 1000.0, 2000.0f);
  p0 = Vertex3f_Texture(position,	Point2f(0.0f, 0.0f));
  p1 = Vertex3f_Texture(position + Vector3f(2000.0f, 0.0f, 0.0f), Point2f(0.0f, 1.0f));
  p2 = Vertex3f_Texture(position + Vector3f(2000.0f, -2000.0f, 0.0f), Point2f(1.0f, 1.0f));
  p3 = Vertex3f_Texture(position + Vector3f(0.0f, -2000.0f, 0.0f), Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad5(p0, p1, p2, p3);

  position = Vector3f(-1000000.0, 1000000.0, 0.0f);
  p0 = Vertex3f_Texture(position,	Point2f(0.0f, 0.0f));
  p1 = Vertex3f_Texture(position + Vector3f(2000000.0f, 0.0f, 0.0f), Point2f(0.0f, 1.0f));
  p2 = Vertex3f_Texture(position + Vector3f(2000000.0f, -2000000.0f, 0.0f), Point2f(1.0f, 1.0f));
  p3 = Vertex3f_Texture(position + Vector3f(0.0f, -1000000.0f, 0.0f),	Point2f(1.0f, 0.0f));
  Quadrilateral<Vertex3f_Texture> quad6(p0, p1, p2, p3);

  quad1.fax_Material(&material);
  quad2.fax_Material(&material);
  quad3.fax_Material(&material);
  quad4.fax_Material(&material);
  quad5.fax_Material(&material);
  vr.render(quad1);
  vr.render(quad2);
  vr.render(quad3);
  vr.render(quad4);
  vr.render(quad5);

  Material material2("grass");
  quad6.fax_Material(&material2);
  vr.render(quad6);
}
