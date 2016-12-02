//
//  ViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "ViewController.h"
#import "AudioPlayViewController.h"
#import "AudioPlayerFlexViewController.h"
#import "PlaySystemMusicViewController.h"
#import "AudioRecordViewController.h"
#import "PlayRomoteAudioViewController.h"
#import "VideoPlayViewController.h"
#import "VideoRecordViewController.h"
#import "TakePhotoViewController.h"

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property(nonatomic,strong)UITableView *tableView;
@property(nonatomic,strong)NSArray     *datas;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addSubview:self.tableView];
    self.title = @"MultiMedia Technology";
    _datas = @[@"audio play",@"audio play flex",@"play system music",@"audio record",@"play remote audio",@"video play",@"video record",@"take photo"];
    [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"reuse"];
    
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _datas.count;
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"reuse"];
    cell.textLabel.text = _datas[indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch (indexPath.row) {
        case 0:{
            AudioPlayViewController *audioPlayVc = [[AudioPlayViewController alloc]init];
            [self.navigationController pushViewController:audioPlayVc animated:YES];
            break;
        }
        case 1:{
            AudioPlayerFlexViewController *audioPlayFlexVc = [[AudioPlayerFlexViewController alloc]init];
            [self.navigationController pushViewController:audioPlayFlexVc animated:YES];
            break;
        }
        case 2:{
            PlaySystemMusicViewController *playerSystemMusicVc = [[PlaySystemMusicViewController alloc]init];
            [self.navigationController pushViewController:playerSystemMusicVc animated:YES];
            break;
        }
        case 3:{
            AudioRecordViewController *audioRecordVc = [[AudioRecordViewController alloc]init];
            [self.navigationController pushViewController:audioRecordVc animated:YES];
            break;
        }
        case 4:{
            PlayRomoteAudioViewController *playRomoteVc = [[PlayRomoteAudioViewController alloc]init];
            [self.navigationController pushViewController:playRomoteVc animated:YES];
            break;
        }

        case 5:{
            VideoPlayViewController *videoPlayVc = [[VideoPlayViewController alloc]init];
            [self.navigationController pushViewController:videoPlayVc animated:YES];
            break;
        }
        case 6:{
            VideoRecordViewController *videoRecordVc = [[VideoRecordViewController alloc]init];
            [self.navigationController pushViewController:videoRecordVc animated:YES];
            break;
        }
        case 7:{
            TakePhotoViewController *takePhotoVc = [[TakePhotoViewController alloc]init];
            [self.navigationController pushViewController:takePhotoVc animated:YES];
            break;
        }
   
        default:
            break;
    }
}
-(UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc]initWithFrame:[UIScreen mainScreen].bounds style:UITableViewStylePlain];
        _tableView.separatorInset = UIEdgeInsetsMake(0, 0, 0, 0);
        _tableView.dataSource = self;
        _tableView.delegate = self ;
        _tableView.tableFooterView = [[UIView alloc]initWithFrame:CGRectZero];
    }
    return _tableView ;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
