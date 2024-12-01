# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。


# 事件枚举一览表

| 枚举值                        | 事件类型描述                                             |
|----------------------------|----------------------------------------------------|
| **None**                    | 无效事件（表示一个无效或未定义的事件）。                            |
| **Timer**                   | 定时器事件（由定时器触发）。                                    |
| **MouseButtonPress**        | 鼠标按键按下事件。                                            |
| **MouseButtonRelease**      | 鼠标按键释放事件。                                           |
| **MouseButtonDblClick**     | 鼠标双击事件。                                               |
| **MouseMove**               | 鼠标移动事件。                                               |
| **KeyPress**                | 键盘按下事件。                                               |
| **KeyRelease**              | 键盘释放事件。                                               |
| **FocusIn**                 | 焦点获得事件（控件获得输入焦点）。                             |
| **FocusOut**                | 焦点丧失事件（控件失去输入焦点）。                             |
| **FocusAboutToChange**      | 焦点即将改变事件（控件即将失去焦点）。                         |
| **Enter**                   | 鼠标进入控件事件。                                           |
| **Leave**                   | 鼠标离开控件事件。                                           |
| **Paint**                   | 绘制控件事件。                                               |
| **Move**                    | 移动控件事件。                                               |
| **Resize**                  | 调整控件大小事件。                                           |
| **Create**                  | 控件创建后触发的事件。                                        |
| **Destroy**                 | 控件销毁时触发的事件。                                        |
| **Show**                    | 控件显示事件。                                               |
| **Hide**                    | 控件隐藏事件。                                               |
| **Close**                   | 请求关闭控件事件。                                           |
| **Quit**                    | 请求退出应用事件。                                           |
| **ParentChange**            | 控件被重新设置父控件时触发的事件。                              |
| **ParentAboutToChange**     | 即将更改父控件的事件。                                        |
| **ThreadChange**            | 对象线程发生变化的事件。                                       |
| **WindowActivate**          | 窗口激活事件（窗口获得焦点）。                                 |
| **WindowDeactivate**        | 窗口失去激活事件（窗口失去焦点）。                             |
| **ShowToParent**            | 向父控件显示事件。                                            |
| **HideToParent**            | 向父控件隐藏事件。                                            |
| **Wheel**                   | 鼠标滚轮事件。                                               |
| **WindowTitleChange**       | 窗口标题变化事件。                                           |
| **WindowIconChange**        | 窗口图标变化事件。                                           |
| **ApplicationWindowIconChange** | 应用程序窗口图标变化事件。                                      |
| **ApplicationFontChange**   | 应用程序字体变化事件。                                         |
| **ApplicationLayoutDirectionChange** | 应用程序布局方向变化事件。                                   |
| **ApplicationPaletteChange**| 应用程序调色板变化事件。                                       |
| **PaletteChange**           | 控件调色板变化事件。                                           |
| **Clipboard**               | 剪切板相关的内部事件。                                         |
| **Speech**                  | 语音输入事件（保留）。                                         |
| **MetaCall**                | 元调用事件（保留）。                                           |
| **SockAct**                 | 套接字激活事件。                                              |
| **WinEventAct**             | Windows 事件激活事件。                                        |
| **DeferredDelete**          | 延迟删除事件。                                               |
| **DragEnter**               | 拖拽进入控件事件。                                            |
| **DragMove**                | 拖拽移动事件。                                               |
| **DragLeave**               | 拖拽离开控件或取消事件。                                      |
| **Drop**                    | 拖拽放置事件。                                               |
| **DragResponse**            | 拖拽响应事件（接受/拒绝）。                                   |
| **ChildAdded**              | 新子控件被添加时触发的事件。                                  |
| **ChildPolished**           | 子控件已完成抛光（绘制）时触发的事件。                         |
| **ChildRemoved**            | 子控件被移除时触发的事件。                                    |
| **ShowWindowRequest**       | 请求将窗口映射（显示）到屏幕。                                |
| **PolishRequest**           | 请求控件被抛光（绘制）。                                      |
| **Polish**                  | 控件已经被抛光（绘制）。                                      |
| **LayoutRequest**           | 控件需要重新布局时触发的事件。                                |
| **UpdateRequest**           | 请求控件重绘时触发的事件。                                    |
| **UpdateLater**             | 请求控件稍后更新（重绘）时触发的事件。                         |
| **EmbeddingControl**        | ActiveX 嵌入事件。                                            |
| **ActivateControl**         | ActiveX 激活事件。                                            |
| **DeactivateControl**       | ActiveX 去激活事件。                                          |
| **ContextMenu**             | 右键菜单事件。                                               |
| **InputMethod**             | 输入法事件。                                                 |
| **TabletMove**              | Wacom 平板移动事件。                                          |
| **LocaleChange**            | 系统语言环境变化事件。                                        |
| **LanguageChange**          | 应用程序语言变化事件。                                        |
| **LayoutDirectionChange**   | 布局方向变化事件。                                            |
| **Style**                   | 内部样式事件。                                               |
| **TabletPress**             | 平板设备按下事件。                                            |
| **TabletRelease**           | 平板设备释放事件。                                            |
| **OkRequest**               | CE (Ok) 按钮按下事件。                                         |
| **HelpRequest**             | 帮助按钮按下事件。                                            |
| **IconDrag**                | 图标拖动事件。                                               |
| **FontChange**              | 字体变化事件。                                               |
| **EnabledChange**           | 启用状态变化事件。                                           |
| **ActivationChange**        | 窗口激活状态变化事件。                                        |
| **StyleChange**             | 样式变化事件。                                               |
| **IconTextChange**          | 图标文本变化事件（已弃用）。                                  |
| **ModifiedChange**          | 修改状态变化事件。                                           |
| **MouseTrackingChange**     | 鼠标跟踪状态变化事件。                                        |
| **WindowBlocked**           | 窗口即将被模态阻塞时触发的事件。                              |
| **WindowUnblocked**         | 窗口模态阻塞解除时触发的事件。                                |
| **WindowStateChange**       | 窗口状态变化事件。                                           |
| **ReadOnlyChange**          | 只读状态变化事件。                                           |
| **ToolTip**                 | 工具提示事件。                                               |
| **WhatsThis**               | “这是什么”提示事件。                                         |
| **StatusTip**               | 状态提示事件。                                               |
| **ActionChanged**           | 动作变化事件。                                               |
| **ActionAdded**             | 动作添加事件。                                               |
| **ActionRemoved**           | 动作移除事件。                                               |
| **FileOpen**                | 文件打开请求事件。                                           |
| **Shortcut**                | 快捷键触发事件。                                             |
| **ShortcutOverride**        | 快捷键覆盖请求事件。                                         |
| **WhatsThisClicked**        | “这是什么”按钮点击事件。                                     |
| **ToolBarChange**           | 工具栏可见性变化事件。                                        |
| **ApplicationActivate**     | 应用程序激活事件（已弃用，使用 `ApplicationStateChange` 替代）。 |
| **ApplicationActivated**    | 应用程序激活事件（已弃用）。                                  |
| **ApplicationDeactivate**   | 应用程序去激活事件（已弃用，使用 `ApplicationStateChange` 替代）。 |
| **ApplicationDeactivated**  | 应用程序去激活事件（已弃用）。                                |
| **QueryWhatsThis**          | 查询“这是什么”帮助事件。                                     |
| **EnterWhatsThisMode**      | 进入“这是什么”模式事件。                                     |
| **LeaveWhatsThisMode**      | 离开“这是什么”模式事件。                                     |
| **ZOrderChange**            | 子控件的 z-order（堆叠顺序）变化事件。                        |
| **HoverEnter**              | 鼠标光标进入 hover 控件事件。                                |
| **HoverLeave**              | 鼠标光标离开 hover 控件事件。                                |
| **HoverMove**               | 鼠标光标在 hover 控件内移动事件。                             |
| **EnterEditFocus**          | 进入编辑模式（键盘导航）事件。                                |
| **LeaveEditFocus**          | 离开编辑模式（键盘导航）事件。                                |
| **AcceptDropsChange**       | 拖拽接收状态变化事件。                                        |
| **ZeroTimerEvent**          | Windows 零定时器事件。                                        |
| **GraphicsSceneMouseMove**  | 图形视图鼠

标移动事件。                                        |
| **GraphicsSceneMouseRelease**| 图形视图鼠标释放事件。                                        |
| **GraphicsSceneMousePress** | 图形视图鼠标按下事件。                                        |
