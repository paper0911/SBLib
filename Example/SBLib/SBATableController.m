//
//  SBATableController.m
//  SBLib
//
//  Created by roronoa on 2017/2/9.
//  Copyright © 2017年 yuki.wang. All rights reserved.
//

#import "SBATableController.h"
#import "SBTableView.h"
#import "SBConstant.h"

@interface SBATableController ()

@property (nonatomic, strong) SBTableView *iTable;

@end

@implementation SBATableController

- (void)viewDidLoad {
    [super viewDidLoad];

    SBWS(__self)

    //
    self.iTable = [[SBTableView alloc] initWithStyle:NO];
    self.iTable.ctrl = self;
    self.iTable.frame = self.view.bounds;
    [self.view addSubview:self.iTable];

    //计算单元格的高度
    self.iTable.heightForRow = ^CGFloat(SBTableView *tableView, NSIndexPath *indexPath) {
        return 44;
    };


    self.iTable.canEditRow = ^(SBTableView *tableView, NSIndexPath *indexPath) {
        return YES;
    };


    self.iTable.editActions = ^NSArray<UITableViewRowAction *> *(SBTableView *tableView, NSIndexPath *indexPath) {
        return [__self editActions];
    };

    // 帐户资料
    SBTableData *sectionData = [[SBTableData alloc] init];
    sectionData.mDataCellClass = [SBTitleCell class];
    [self.iTable addSectionWithData:sectionData];

    NSArray *titleArray = @[@"a",
                            @"b",
                            @"c",
                            @"d",
                            ];

    //单元格
    for (int i = 0; i < titleArray.count; i++) {
        DataItemDetail *detail = [DataItemDetail detail];
        [detail setString:titleArray[i] forKey:__KEY_CELL_TITLE];
        [sectionData.tableDataResult addItem:detail];
    }

    [self.iTable reloadData];
}

- (NSArray *)editActions {
    NSMutableArray *actions = [NSMutableArray array];
    UITableViewRowAction *action = [UITableViewRowAction rowActionWithStyle:UITableViewRowActionStyleNormal title:@"忽略未读" handler:^(UITableViewRowAction * _Nonnull action, NSIndexPath * _Nonnull indexPath) {

    }];
    [actions addObject:action];

    UITableViewRowAction *action2 = [UITableViewRowAction rowActionWithStyle:UITableViewRowActionStyleDestructive title:@"删除" handler:^(UITableViewRowAction * _Nonnull action, NSIndexPath * _Nonnull indexPath) {

    }];
    [actions addObject:action2];

    return actions;
}


@end
