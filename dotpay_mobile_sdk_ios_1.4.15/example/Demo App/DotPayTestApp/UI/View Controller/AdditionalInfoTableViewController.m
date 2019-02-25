//
// Created by mmackowiak on 09.10.2015.
// Copyright (c) 2015 CTM Mobiltek. All rights reserved.
//

#import "AdditionalInfoTableViewController.h"
#import "AdditionalInfoCellTableViewCell.h"
#import "AdditionalInfo.h"

NSString * const kAddititionalInfoKey = @"kAddititionalInfoKey";

@interface AdditionalInfoTableViewController ()
@property(nonatomic, strong) UIBarButtonItem * addButtonItem;
@end

@implementation AdditionalInfoTableViewController


-(void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Additional Info";
    self.navigationItem.rightBarButtonItems = @[self.editButtonItem, self.addButtonItem];
    self.additionalInfoStore = [NSUserDefaults standardUserDefaults];
    if (!self.additionalInfos) {
        self.additionalInfos = [NSKeyedUnarchiver unarchiveObjectWithData:[self.additionalInfoStore objectForKey:kAddititionalInfoKey]];
    }
    if (!self.additionalInfos) {
        self.additionalInfos = [NSMutableArray new];
        NSData *data = [NSKeyedArchiver archivedDataWithRootObject:self.additionalInfos];
        [self.additionalInfoStore setObject:data forKey:kAddititionalInfoKey];
        [self.additionalInfoStore synchronize];
    }
}


- (UIBarButtonItem *)addButtonItem {
    if(_addButtonItem){
        return _addButtonItem;
    }
    _addButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAdd target:self action:@selector(addButtonTapped:)];
    return _addButtonItem;
}


- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.additionalInfos.count;
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell* cell  = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"Cell"];;
    AdditionalInfo* additionalInfo = self.additionalInfos[indexPath.row];
    cell.textLabel.text = additionalInfo.key;
    cell.detailTextLabel.text = additionalInfo.value;
    
    return cell;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        [self.additionalInfos removeObjectAtIndex:indexPath.row];
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
        [self updateAdditionalInfoArray];
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    AddInfoViewController *addInfoController = [[AddInfoViewController alloc] initWithNibName:@"AddInfoViewController" bundle:nil];
    addInfoController.info = self.additionalInfos[indexPath.row];
    addInfoController.indexPath = indexPath;
    addInfoController.delegate = self;
    [self.navigationController pushViewController:addInfoController animated:YES];
    [self.tableView reloadData];
    
}

- (void) addButtonTapped:(id)sender{
    AddInfoViewController *addInfoController = [[AddInfoViewController alloc] initWithNibName:@"AddInfoViewController" bundle:nil];
    addInfoController.delegate = self;
    [self.navigationController pushViewController:addInfoController animated:YES];
    
}


- (void) updateAdditionalInfoArray{
    [self.additionalInfoStore setObject:[NSKeyedArchiver archivedDataWithRootObject:self.additionalInfos] forKey:kAddititionalInfoKey];
    [self.additionalInfoStore synchronize];
    [self.tableView reloadData];
    
}

#pragma mark - AddInfoViewControllerDelegate
- (void)addInfoViewController:(AddInfoViewController *)viewController saveInfo:(AdditionalInfo *)info atIndexPath:(NSIndexPath *)indexPath{
    if (!indexPath) {
        [self.additionalInfos addObject:info];

    }else{
        [self.additionalInfos replaceObjectAtIndex:indexPath.row withObject:info];
    }
    [self updateAdditionalInfoArray];
}

@end
