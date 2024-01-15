//
//  bridge.hpp
//  AUOximeter
//
//  Created by Li Yun Jung on 2023/3/21.
//  Copyright © 2023 Aulisa. All rights reserved.
//

#ifndef bridge_hpp
#define bridge_hpp

#ifdef __cplusplus
extern "C" {
#endif

void CPPAnalysis(int beginning_point, float* waveform, int* beat_location, int length, char* beat_type_array, int interpretation);
void pythonTest();

#ifdef __cplusplus
}
#endif

#endif /* bridge_hpp */
