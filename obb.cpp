
/// <summary>
/// 
/// 0 : no collision, behind plane normal
/// 1 : no collision, front of plane normal
/// 2 : collision
/// 
/// </summary>
/// <param name="cube"></param>
/// <param name="plane"></param>
/// <returns></returns>
int Collision::CubeToPlane(Cube& cube, Plane& plane)
{
    Vector3 cubePosVec = cube.center - plane.point1;
    Vector3 distanceVec = cubePosVec - (plane.planeVec * (cubePosVec | plane.planeVec));

    // front           // back
    // flt      frt    // blt      max
    //                 //
    // min      frb    // blb      brb
    //
    // flt, frt, frb, min, blt, max, brb, blb 

    // ���߿� ȸ�� ����
    Vector3 conerPoint[8] = { cube.min + Vector3(0,cube.size.y,0), cube.min + Vector3(cube.size.x,cube.size.y,0)
                            , cube.min + Vector3(cube.size.x,0,0), cube.min
                            , cube.max + Vector3(-cube.size.x,0,0), cube.max
                            , cube.max + Vector3(0,-cube.size.y,0), cube.max + Vector3(-cube.size.x,-cube.size.y,0) };

    Vector3 cubeVecX = (conerPoint[2] - conerPoint[3]).GetNomalVector() * 0.5f;
    Vector3 cubeVecY = (conerPoint[0] - conerPoint[3]).GetNomalVector() * 0.5f;
    Vector3 cubeVecZ = (conerPoint[7] - conerPoint[3]).GetNomalVector() * 0.5f;

    float sum = (cubeVecX | plane.normal) + (cubeVecY | plane.normal) + (cubeVecZ | plane.normal);

    if(fabs(sum) >= (distanceVec | plane.normal))
	    return 2;

    if(0 > (distanceVec | plane.normal))
        return 0;

    return 1;
}
