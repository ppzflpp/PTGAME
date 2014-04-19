LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := PTGame/main.cpp \
                   PTGame/AppDelegate.cpp \
                   PTGame/PTScene.cpp \
                   PTGame/sprite/ImageManager.cpp \
                   PTGame/sprite/ImageSprite.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/PTGame/include    

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
