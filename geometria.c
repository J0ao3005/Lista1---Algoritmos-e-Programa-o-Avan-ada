// geometria.c
#include "geometria.h"
#include <math.h>

double distPP(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double orient(Point A, Point B, Point C) {
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

static int onSegment(Point p, Point a, Point b) {
    return (p.x >= fmin(a.x, b.x) - EPSILON && p.x <= fmax(a.x, b.x) + EPSILON &&
            p.y >= fmin(a.y, b.y) - EPSILON && p.y <= fmax(a.y, b.y) + EPSILON);
}

int segmentosIntersectam(Segment s1, Segment s2) {
    Point A = s1.a, B = s1.b, C = s2.a, D = s2.b;
    double d1 = orient(C, D, A), d2 = orient(C, D, B);
    double d3 = orient(A, B, C), d4 = orient(A, B, D);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return 1;

    if (fabs(d1) < EPSILON && onSegment(A, C, D)) return 1;
    if (fabs(d2) < EPSILON && onSegment(B, C, D)) return 1;
    if (fabs(d3) < EPSILON && onSegment(C, A, B)) return 1;
    if (fabs(d4) < EPSILON && onSegment(D, A, B)) return 1;

    return 0;
}

double distPontoSegmento(Point p, Segment s) {
    double dx = s.b.x - s.a.x, dy = s.b.y - s.a.y;
    double len2 = dx*dx + dy*dy;
    if (len2 < EPSILON) return distPP(p, s.a);
    double t = fmax(0.0, fmin(1.0, ((p.x - s.a.x)*dx + (p.y - s.a.y)*dy) / len2));
    Point proj = { s.a.x + t*dx, s.a.y + t*dy };
    return distPP(p, proj);
}

int dentroDominio(Point p, double R) {
    return (p.x*p.x + p.y*p.y <= R*R);
}