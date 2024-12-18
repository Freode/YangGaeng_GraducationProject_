# YangGaeng_GraducationProject_Final
Graduation Project - 화재상황대처 기능성 게임 콘텐츠


<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaneg_Title.png?raw=true" alt="Image 9" width="500">


## 요약
Unreal Engine 5을 기반으로 시나리오별 화재 상황에 대한 대처를 할 수 있는 기능성 게임 콘텐츠를 개발했습니다.


## 기간
2024.04. ~ 2024.06. (3개월)


## 참여 인원 및 역할
총 4명
- 최정호(본인) : 팀장 - 
- 김연경 : 팀원 - 총기

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

---
<table>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/K_YangGaeng/blob/main/ReadMeImage/ReadMe_Image_8.png?raw=true" alt="Image 8" width="500">
        <figcaption>Notion : 기획서 목차</figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/K_YangGaeng/blob/main/ReadMeImage/ReadMe_Image_10.png?raw=true" alt="Image 10" width="500">
        <figcaption>Notion : 참고 애셋</figcaption>
      </figure>
    </td>
  </tr>
  <tr>
    <td style="text-align: center;">
      <figure>
        <img src = "https://github.com/Freode/K_YangGaeng/blob/main/ReadMeImage/ReadMe_Image_7.png?raw=true" alt="Image 7" width="500">
        <figcaption>Notion : 무기 기능 기획서 작성</figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src = "https://github.com/Freode/K_YangGaeng/blob/main/ReadMeImage/ReadMe_Image_11.png?raw=true" alt="Image 11" width="500">
        <figcaption>Notion : 이동 기능 기획서 작성</figcaption>
      </figure>
    </td>
  </tr>
</table>


## 기획 및 플로우차트


### 시나리오
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_1.png?raw=true" alt="YangGaeng_FlowChart_1">


### 프레임워크
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_2.png?raw=true" alt="YangGaeng_FlowChart_2">


### 메인 & 스테이지 화면 세부 플로우차트
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_6.png?raw=true" alt="YangGaeng_FlowChart_6">


## 본인 역할
<img src = "https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaeng_FlowChart_5.png?raw=true" alt="YangGaeng_FlowChart_5">


캐릭터 이동, 파쿠르, 대쉬 스킬 등의 캐릭터 파트와 캐릭터 애니메이션 블루프린트에 총기를 사용할 수 있도록 Aim Offset을 추가하는 파트까지 담당했습니다.
현재 본인 파트는 개발을 완료했으며, 나머지 팀원들의 파트를 보조 및 피드백을 통해 총괄하고 있습니다.


### USavaSlot 클래스를 이용한 플레이어 정보 저장
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


## 시연 영상
[![시연 영상](https://github.com/Freode/YangGaeng_GraducationProject_Final/blob/main/ReadMeImage/YangGaneg_Title.png)](https://youtu.be/kSwMCccAWC8)
- 클릭하시면, 시연 영상으로 이동합니다.


## 느낀점
