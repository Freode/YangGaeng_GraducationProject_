# YangGaeng_GraducationProject_Final
Graduation Project - 화재상황대처 기능성 게임 콘텐츠


<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_Title.png?raw=true" alt="YangGaeng_Title.png" width="500">


## 요약
Unreal Engine 5을 기반으로 시나리오별 화재 상황에 대한 대처를 할 수 있는 기능성 게임 콘텐츠를 개발했습니다.


## 기간
2024.04. ~ 2024.06. (3개월)


## 참여 인원 및 역할
총 4명
- 최정호(본인) : 팀장
- 김연경 : 팀원

- 비중 : FE(65%), 기획(60%)

---


팀원 Git 링크
- 김연경 : https://github.com/yeonkyeong1022


## 언어
- C++ & Unreal C++

  
## 사용 툴
- Unreal Engine 5.2


## 협업 툴
- Github : 협업 코드 저장소
- Notion : 기획 & 일정 관리
- Figma : 기초 UI 틀 및 디자인


## 기획 및 플로우차트


### 시나리오
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_1.png?raw=true" alt="YangGaeng_FlowChart_1">


### 프레임워크
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_2.png?raw=true" alt="YangGaeng_FlowChart_2">


### 메인 & 스테이지 화면 세부 플로우차트
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_6.png?raw=true" alt="YangGaeng_FlowChart_6">


## 본인 역할
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_5.png?raw=true" alt="YangGaeng_FlowChart_5">



해당 콘텐츠를 제작하기 위한 메인 시스템들 위주로 개발했습니다.
저장 및 백업 시스템, 스테이지 관리, 시나리오 클래스, 상호작용 모듈화, 게임적 요소 UI, 소화기 애니메이션 및 FX, 도구 설명서 UI 등을 개발했습니다.


### USavaSlot 클래스를 이용한 플레이어 정보, 스테이지 클리어 정보 저장
<table>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_IntroductionImage_3.png?raw=true" alt="YangGaeng_IntroductionImage_1" width="500">
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FrameworkWithSaveSlot.gif?raw=true" alt="YangGaeng_FrameworkWithSaveSlot" width="500">
      </figure>
    </td>
  </tr>
</table>


- '바운스볼' 게임의 스테이지 선택 부분을 참고해 이전 스테이지를 통과해야만, 다음 스테이지로 이동 가능하도록 구현했습니다.
- 'SaveSlot'을 이용해 데이터를 'sav' 파일로 저장해 스테이지 클리어 저장 및 불러오기가 가능하도록 구현했습니다.


### 시나리오 담당 클래스
<table>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_IntroductionImage_3.png?raw=true" alt="YangGaeng_IntroductionImage_3" width="500">
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_IntroductionImage_4.png?raw=true" alt="YangGaeng_IntroductionImage_4" width="500">
      </figure>
    </td>
  </tr>
</table>


- 스테이지 레벨마다 시나리오 담당 객체를 싱글턴으로 둬 관리가 용이하도록 했습니다.
- 'Interacts'라는 배열에 도구 사용 순서를 자유롭게 설정 가능합니다.
  

### 상호작용 클래스 모듈화
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_InteractionHighlighting.gif?raw=true" alt="YangGaeng_InteractionHighlighting" width="600">


### 소화기 애니메이션 및 상호작용 기능 개발
<table>
  <tr>
    <td>
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_IntroductionImage_5.png?raw=true" alt="YangGaeng_IntroductionImage_5" width="500">
        <figcaption>소화기 애니메이션 제작 및 소켓 활용</figcaption>
      </figure>
    </td>
  </tr>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FireExtinguisher_1.gif?raw=true" alt="YangGaeng_FireExtinguisher_1" width="500">
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FireExtinguisher_2.gif?raw=true" alt="YangGaeng_FireExtinguisher_2" width="500">
      </figure>
    </td>
  </tr>
</table>


- 스켈레탈 본을 조작해 소화기를 잡고 있는 애니메이션 시퀀스를 제작했습니다.
- 소켓과 애님 인스턴스를 이용해 애니메이션을 재생하며, 별도의 FX를 제작해 추가했습니다.
- 마우스 좌클릭 시, 일정 시간마다 전방으로 나아가는 소화약제 FX가 생성됩니다. 


### Widget을 사용한 게임적 요소 추가
<table>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_StageClearAndScore.gif?raw=true" alt="YangGaeng_StageClearAndScore" width="500">
        <figcaption>타이머와 체력 기반으로 점수 측정</figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_HealthReduce_1.gif?raw=true" alt="YangGaeng_HealthReduce_1" width="500">
        <figcaption>화재 연기로 인한 체력 감소</figcaption>
      </figure>
    </td>
  </tr>
</table>


- 게임적 요소를 위해 체력, 타이머, 점수 UI를 추가했습니다.
- 체력이 모두 소진하면, 스테이지 클리어 실패가 됩니다.
- 체력과 남은 시간에 따라, 점수가 결정됩니다.


## 시연 영상
[![시연 영상](https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_Title.png)](https://youtu.be/kSwMCccAWC8)
- 클릭하시면, 시연 영상으로 이동합니다.


## 느낀점
- Unreal Engine 5를 활용한 첫 프로젝트로 다양한 버전의 Unreal Engine을 사용할 수 있는 자신감을 얻게 되었습니다.
