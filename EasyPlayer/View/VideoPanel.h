
#import <UIKit/UIKit.h>
#import "VideoView.h"

typedef NS_OPTIONS(NSInteger, IVideoLayout){
    IVL_One = 1,
    IVL_Four = 4,
    IVL_Nine = 9,
};

@protocol VideoPanelDelegate;

@interface VideoPanel : UIView

@property (nonatomic, weak) id<VideoPanelDelegate> delegate;

@property (nonatomic, strong) VideoView *activeView;
@property (nonatomic, assign) IVideoLayout layout;

- (VideoView *) nextAvailableContainer;

// 重启全部视频的播放
- (void) restore;

// 停止全部视频的播放
- (void) stopAll;

@end

@protocol VideoPanelDelegate <NSObject>

@optional
- (void) activeViewDidiUpdateStream:(VideoView *)view;
- (void) didSelectVideoView:(VideoView *)view;
- (void) activeVideoViewRendStatusChanged:(VideoView *)view;

- (void) videoViewWillAnimateToFullScreen:(VideoView *)view;
- (void) videoViewWillAnimateToNomarl:(VideoView *)view;

// 添加新视频源
- (void) videoViewWillAddNewRes:(VideoView *)view;

@end