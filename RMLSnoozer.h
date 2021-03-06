#import <Foundation/Foundation.h>

@protocol RMLSnoozerDelegate <NSObject>
-(void)snoozeCallback:(id)payload;
@end


@interface RMLSnoozer : NSObject {
  int _minutes;
  BOOL _pendingEvent;
  id <RMLSnoozerDelegate> _delegate;
  NSTimer *_snoozeTimer;
}

@property (assign) int minutes;
@property (assign) BOOL pendingEvent;
@property (nonatomic, retain) id /*RMLSnoozerDelegate*/ delegate;
@property (nonatomic, retain) NSTimer *snoozeTimer;

-(id)initWithTime:(int)minutes delegate:(id <RMLSnoozerDelegate>)delegate;
-(void)snooze:(id)payload;
-(void)invalidate;

@end
