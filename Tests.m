
#import <XCTest/XCTest.h>
#import "DeltoidClass.h"


using namespace Del;

@interface test : XCTestCase

@end


@implementation test


- (void)testEmptyConstructor {
    Deltoid obj;
    XCTAssertEqualWithAccuracy(1.0, obj.getr(), 0.001);
}


- (void)defaultConstructor {
    Deltoid obj(5.6);
    XCTAssertEqualWithAccuracy(5.6, obj.getr(), 0.001);
}


- (void)testSerR {
    Deltoid d(3.2);
    XCTAssertNoThrow(d.setr(2.6));
    XCTAssertEqualWithAccuracy(2.6, d.getr(), 0.001);
    //XCTAssertThrows(Deltoid obj2(-2));
    XCTAssertThrows(d.setr(-2));
    XCTAssertThrows(d.setr(0));
}


- (void)testEquation {
    Deltoid obj(2.4);
    XCTAssertEqual("Неявное уравнение в декартновой системе координат (При r = 1): (x^2 + y^2)^2 + 18(x^2 + y^2) = 8x^3 - 24y^2x + 27", obj.equation());
}


- (void)testGetLengthOfIntersection {
    Deltoid obj(1.0);
    XCTAssertEqualWithAccuracy(4.0, obj.get_length_of_intersection(), 0.001);
    Deltoid obj2(3.2);
    XCTAssertEqualWithAccuracy(12.8, obj2.get_length_of_intersection(), 0.001);
}


- (void)testGetLength {
    Deltoid obj(3.2);
    XCTAssertEqualWithAccuracy(17.07, obj.get_length(), 0.01);
    Deltoid obj2(5.0);
    XCTAssertEqualWithAccuracy(26.7, obj2.get_length(), 0.1);
}


-(void)testGetArea {
    Deltoid obj(2.1);
    XCTAssertEqualWithAccuracy(3.08, obj.get_area(), 0.1);
    Deltoid obj2(0);
    XCTAssertEqualWithAccuracy(0, obj2.get_area(), 0.1);
}


-(void)testGetCoords {
    double x1, x2;
    Deltoid obj(2.6);
    XCTAssertNoThrow(obj.get_coords(2.5, x1, x2));
    XCTAssertEqualWithAccuracy(7.78, x1, 0.1);
    XCTAssertEqualWithAccuracy(0.45, x2, 0.1);
}

@end
