#ifndef YRTVectorH
#define YRTVectorH

class TYRTVector
{
public:
    float X, Y, Z;
    TYRTVector();
    TYRTVector(float a);
    TYRTVector(float x, float y, float z);
    TYRTVector operator+ (const TYRTVector& arg);
    TYRTVector operator- (const TYRTVector& arg);
    TYRTVector operator* (const TYRTVector& arg);
    float GetDistance(TYRTVector& arg);
    float GetDistanceSqr(TYRTVector& arg);
    bool IsNearZero(void);
    friend bool operator == (const TYRTVector& v1, const TYRTVector& v2);
};

TYRTVector operator* (float s, const TYRTVector& arg);

#endif
