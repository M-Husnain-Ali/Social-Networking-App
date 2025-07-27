# 🌐 Social Networking Application

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple.svg)](https://visualstudio.microsoft.com/)

A sophisticated C++ implementation of a social networking system that mirrors core Facebook functionalities. This project demonstrates advanced object-oriented programming concepts, robust memory management, and efficient data structures.

**Author:** Muhammad Husnain Ali  
**Repository:** [Social-Networking-App](https://github.com/M-Husnain-Ali/Social-Networking-App)

## 📋 Table of Contents
- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Technical Details](#technical-details)
- [File Structure](#file-structure)

## 🎯 Overview
This social networking application is a comprehensive C++ project that implements a Facebook-like social platform. It features a robust object-oriented architecture with the following key aspects:

### Core System Design
- **Object-Oriented Hierarchy:** Implements a well-structured class hierarchy with abstract base classes and derived implementations
- **Memory Management:** Custom memory handling with proper allocation and deallocation
- **File-Based Persistence:** Efficient data storage and retrieval system
- **Dynamic Data Structures:** Custom implementations of dynamic arrays and relationships

### Social Features Implementation
- **User Network:** Complete friend system with bidirectional relationships
- **Content Management:** Sophisticated post and comment system
- **Activity System:** Tracks and displays user activities and interactions
- **Memory Feature:** "On This Day" style functionality for past content

## 💻 Requirements
- Windows 10/11
- Microsoft Visual Studio 2022
  - Desktop development with C++ workload
  - Windows 10/11 SDK (10.0.26100 or later)
- C++ Standard: C++14 or later
- Minimum screen resolution: 1024x768

## 🚀 Installation & Setup

1. **Get the Code**
   ```bash
   git clone https://github.com/M-Husnain-Ali/Social-Networking-App.git
   ```
   Or download directly from [repository](https://github.com/M-Husnain-Ali/Social-Networking-App)

2. **Project Setup**
   - Open Visual Studio 2022
   - Create new Empty Project (C++)
   - Add the existing file `project-code.cpp` to your project

3. **Add Data Files**
   Copy these files to your project directory:
   ```
   Users.txt
   Pages.txt
   Posts.txt
   Comments.txt
   ```

4. **Configure Project**
   - Right-click on project in Solution Explorer
   - Select `Properties`
   - Set C++ Language Standard to C++17 or later

5. **Run the Application**
   - Press `F5` to build and run
   - Or use `Ctrl + F5` for run without debugging

## ⚠️ Common Issues
- Ensure all data files are in the correct project directory
- Check Visual Studio installation includes necessary C++ components
- Verify file paths in the code match your project structure
- Make sure C++ language standard is set correctly

## ✨ Features

### 👤 User Management System
- **Profile System**
  - Unique user identification
  - First and last name management
  - Friend list maintenance
  - Liked pages tracking
  - Personal timeline
  - Custom news feed algorithm

- **Friend Network**
  - Bidirectional friendship relationships
  - Friend list viewing
  - Friend activity tracking
  - Maximum 10 friends per user (expandable)

### 📱 Page System
- **Page Management**
  - Unique page identification
  - Title and content management
  - Post timeline
  - Follower tracking
  - Activity monitoring
  - Maximum 10 pages per user (expandable)

### 📝 Post System
- **Content Types**
  - Regular text posts
  - Activity-based posts
  - Memory posts (throwbacks)
  - Comments and reactions

- **Post Features**
  - Unique post identification
  - Timestamp tracking
  - Like system
  - Comment system
  - Share functionality
  - Maximum 10 posts per timeline (expandable)

### 💭 Comment System
- Unique comment identification
- User attribution
- Timestamp tracking
- Text content management
- Maximum 10 comments per post (expandable)

### 🕒 Activity Tracking
- **Types of Activities**
  - Feeling
  - Thinking
  - Making
  - Celebrating

### 📅 Memory System
- **Throwback Features**
  - Past post recall
  - Date-based filtering
  - Share with new context
  - Automatic date difference calculation

## 🏗️ System Architecture
```
Object (Abstract)
├── User
└── Page

Post
├── Regular Post
└── Memory Post

Supporting Classes
├── Helper
├── Output
├── Date
├── Activity
└── Comment
```

## 🏗️ Technical Details

### Class Architecture
1. **Helper Class**
   - String manipulation utilities
   - Memory management helpers
   - ID generation system
   - String comparison tools
   - Type conversion utilities

2. **Object Class (Abstract)**
   - Base class for User and Page
   - Virtual function framework
   - Common ID management
   - Timeline functionality

3. **User Class**
   - Profile data management
   - Friend list operations
   - Page following system
   - Timeline management
   - Post creation and sharing
   - Memory viewing system

4. **Page Class**
   - Content management
   - Post timeline
   - Follower tracking
   - Activity monitoring

5. **Post Class**
   - Content management
   - Like system
   - Comment system
   - Activity integration
   - Memory sharing capability

6. **Memory Class**
   - Original post linking
   - Date difference calculation
   - Custom display formatting

7. **Activity Class**
   - Activity type management
   - Content formatting
   - Display integration

8. **Date Class**
   - Date management
   - Comparison operations
   - Memory date calculations

9. **Facebook Class (Controller)**
   - Central system management
   - File operations
   - Object relationships
   - Search functionality
   - Memory sharing system

### Memory Management
- **Dynamic Allocation**
  - Custom array management
  - Proper deallocation
  - Memory leak prevention
  - Resource cleanup

### File System
- **Data Storage**
  - User information
  - Page data
  - Post content
  - Comment records
  - Relationship data

### Performance Considerations
- Fixed array sizes for predictable memory usage
- Efficient string manipulation
- Optimized search algorithms
- Smart memory management

## 📁 File Structure
```
Social-Networking-App/
├── 22L-6562 Project.cpp    # Main source code
├── Users.txt               # User data
├── Pages.txt              # Page information
├── Posts.txt             # Post content
└── Comments.txt          # Comment data
```

## 📊 Example Data Format

### Users.txt
```
[Total Users Count]
[UserID] [FirstName] [LastName]
[FriendID1] [FriendID2] ... -1
[PageID1] [PageID2] ... -1
```

### Pages.txt
```
[Total Pages Count]
[PageID] [PageTitle]
```

### Posts.txt
```
[Total Posts Count]
[PostType] [PostID] [Date] [Content]
[SharedByID]
[LikedByID1] [LikedByID2] ... -1
```

### Comments.txt
```
[Total Comments Count]
[CommentID] [PostID] [UserID] [Content]
```

---

<div align="center">
Made with ❤️ by Muhammad Husnain Ali
</div>